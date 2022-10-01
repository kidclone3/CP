

def zeroMove(fileName):
    '''
    Hoàn thiện phương thức zeroMove(fileName), phương thức này thực hiện việc đọc các số nguyên

    từ file fileName, các số nguyên được viết trên 1 dòng, mỗi số cách nhau bởi 1 dấu cách. Lưu các số này vào
    
    trong một danh sách theo đúng thứ tự trong fileName
    
    Thực hiện việc di chuyển các số 0 về phía bên phải của danh sách trong khi vẫn giữ nguyên thứ tự của các số khác.
    
    Hàm zeroMove trả lại danh sách sau khi thực hiện việc di chuyển số 0.
    
    
    
    > Ví dụ cho file data.txt có nội dung như sau:
    
    0 1 0 3 12
    
    > Kết quả trả về là
    
    [1, 3, 12, 0, 0]
    '''
    result = []
    cnt = 0
    data = [int(i) for i in open(fileName).readline().split()]
    for i in data:
        if i == 0:
            cnt += 1
        else:
            result.append(i)
    return result + [0 for i in range(cnt)]