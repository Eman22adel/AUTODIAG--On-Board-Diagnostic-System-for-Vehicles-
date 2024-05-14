import serial
import openpyxl

ser = serial.Serial(port='COM3', baudrate= 115200, bytesize=8, timeout=10, stopbits=serial.STOPBITS_ONE)

def read_excel_to_array(path, max_row, max_column):
    wb = openpyxl.load_workbook(path)
    sheet = wb.active
    data = []
    for row in sheet.iter_rows(min_row=2, max_row=max_row, min_col=1, max_col=max_column, values_only=True):
        row_data = [] 
        for    cell in row:
            cell = str(cell)
            row_data.extend(cell.split(','))
        # Split the row data into two parts
        part1 = row_data[:4]
        part2 = row_data[4:]
        # Add a comma between the two parts
        data.append([part1,part2])
    return data
data = read_excel_to_array("C:\\Users\\emana\\Desktop\\Python\\data.xlsx", 2061, 8)
counter_100 = 0

def send_data(data):
    # Convert the data to a string, separated by commas, if it's not already
    if isinstance(data, list):
        data = ','.join(map(str, data))
    # Convert the data to bytes
    data = data.encode()  
    # Write the data to the serial port
    ser.write(data)
    print(data)

def function1():
    global counter_100
    send_data(data[counter_100][0])
    send_data(',')
    send_data(data[counter_100][1])
    send_data(',')
    counter_100 += 1

while True:
    if ser.in_waiting > 0:
        received_id = ser.readline().decode('utf-8').strip('\x00').strip()
        print(f"Received: {received_id}")
        if received_id == "Remote frame":
            function1()
        else:
            print("not found")
