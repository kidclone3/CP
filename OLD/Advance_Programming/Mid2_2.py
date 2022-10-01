import numpy as np
class ComplexNumber:
    '''
     Lớp thực hiện tạo đối tượng số phức cùng với các phép toán cơ bản,
     số phức (a + bi) có phần thực và phần ảo là số thực
     Các phép toán gồm phép cộng, phép trừ, phép nhân, phép chia.
     
    '''
    
    def __init__(self, real, image):
        '''
            Hàm dựng  của số phức  gồm phần thực real và phần ảo image
            Chú ý tên của thuộc tính tử số và mẫu số đặt giống như trên (real và image)
        '''
        self.real = real
        self.image = image
        pass
    
    def addComplex(self, frac):
        '''
            Hàm trả lại kết quả là phép cộng của phân số hiện tại với phân số frac
            ví dụ (2+3i)+(4+5i) thì kết quả là (6 + 8i)
        '''
        
       pass
    
    def subComplex(self, frac):
        '''
            Hàm trả lại kết quả là phép trừ của phân số hiện tại với phân số frac
            ví dụ (2+3i)-(4+5i) thì kết quả là (-2 + -2i)
        '''
       pass
        
    def multiComplex(self, frac):
        '''
            Hàm trả lại kết quả là phép nhân của phân số hiện tại với phân số frac
            ví dụ (2+3i)*(4+5i) thì kết quả là (-7 + 22i)
        '''
       pass
    
    def divComplex(self, frac):
        '''
            Hàm trả lại kết quả là phép chia của phân số hiện tại với phân số frac
            ví dụ (2+3i):(4+5i) thì kết quả là (0.561 + 0.049i)
        '''
        pass
    
    
    def toString(self):
        '''
            Hàm trả lại chuỗi biểu diễn số phức bởi phần thực và phần ảo làm tròn đến 3 chữ số
            ví dụ phần thực = 5, phần ảo = 3 kết quả là chuỗi '5 + 3i'
            Hàm này được viết sẵn, sinh viên không chỉnh sửa
        '''
        return str(round(self.real,3)) + ' + ' + str(round(self.image,3))+'i'

'''
    Chú ý, các phương thức sẽ được gọi đến để chấm điểm, 
    do vậy bài nộp của sinh viên cần phải bỏ hết (hoặc comment #) các lệnh in ra màn hình
     
'''


def testDemo():
   
    a = ComplexNumber(2, 3)
    b = ComplexNumber(4, 5)
    
    print(a.addComplex(b).toString())
    print(a.subComplex(b).toString())
    print(a.multiComplex(b).toString())
    print(a.divComplex(b).toString())

'''
Bỏ comment lệnh testDemo() dưới đây để chạy test chương trình, và comment lại lệnh đó khi nộp bài
'''
testDemo()

