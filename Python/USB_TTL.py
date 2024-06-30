import os  # type: ignore
import serial  # type: ignore
import openpyxl  # type: ignore
from tabulate import tabulate  # type: ignore

# Initialize serial communication
ser = serial.Serial(port='COM3', baudrate=115200, bytesize=8, timeout=10, stopbits=serial.STOPBITS_ONE)

# Function to read Excel data into a structured array
def read_excel_to_array(path, max_row, max_column):
    wb = openpyxl.load_workbook(path)
    sheet = wb.active
    data = []
    for row in sheet.iter_rows(min_row=2, max_row=max_row, min_col=1, max_col=max_column, values_only=True):
        row_data = [] 
        for cell in row:
            if cell is None:
                cell_str = '0'
            else:
                cell_str = str(int(float(cell))) if isinstance(cell, (float, int)) else str(cell)
            row_data.extend(cell_str.split(','))
        part1 = row_data[:4]
        part2 = row_data[4:]
        data.append([part1, part2])
    return data

data = read_excel_to_array("D:\\idea\\Python_Script\\data.xlsx", 2061, 8)
counter_100 = 0

# Function to send data over serial port
def send_data(data):
    if isinstance(data, list):
        data = ','.join(map(str, data))
    data = data.encode()
    ser.write(data)

# Function to format and print sensor data
def print_sensor_data():
    sensors = [
        ["ENGINE POWER Sensor", data[counter_100][0][0]],
        ["ENGINE COOLANT Sensor", data[counter_100][0][1]],
        ["ENGINE LOAD Sensor", data[counter_100][0][2]],
        ["ENGINE RPM Sensor", data[counter_100][0][3]],
        ["INTAKE MANIFOLD PRESSURE Sensor", data[counter_100][1][0]],
        ["AIR INTAKE TEMP Sensor", data[counter_100][1][1]],
        ["THROTTLE POS Sensor", data[counter_100][1][2]],
        ["TIMING ADVANCE Sensor", data[counter_100][1][3]],
    ]
    
    table = tabulate(sensors, headers=["Sensor", "Value"], tablefmt="grid")
    print(table)

# Main function to send data and print sensor information
def function1():
    global counter_100
    send_data(data[counter_100][0])
    send_data(',')
    send_data(data[counter_100][1])
    send_data(',')
    print_sensor_data()
    counter_100 += 1
    if counter_100 == 2062:
       counter_100 = 0


# Main loop to receive data and trigger function1
while True:
    
    if ser.in_waiting > 0:
        received_id = ser.readline().decode('utf-8').strip('\x00').strip()


        if received_id == "1":
            
            os.system('cls' if os.name == 'nt' else 'clear')  # Clear the cmd
            print("\n\n\n")
            print("\033[1;93m \t\t AUTODIAG \033[0m \n\n\n")
            print("\033[1;32m Diagnostic Request Remote frame  \033[0m")
            function1()
        else:
            os.system('cls' if os.name == 'nt' else 'clear')  # Clear the cmd
            print("\033[1;32m No frame  \033[0m")





