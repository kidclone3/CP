for i in range(1, 7):
    for j in range(1, 6-i+2):
        print(f"var x{i}{j} >= 0;")
print("maximize z: x11;")

cnt = 1;
for i in range(1, 6):
    for j in range(1, 6-i+1):
        print(f"subject to c{cnt}: x{i}{j} - x{i}{j+1} >= x{i+1}{j};")
        cnt+=1
        print(f"subject to c{cnt}: x{i}{j} - x{i}{j+1} <= x{i+1}{j};")
        cnt+=1
print("end;")
