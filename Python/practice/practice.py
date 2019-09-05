class Student:
    def __init__(self,name, age):
        self.name = name
        self.age = age

    def printf(self):
        a = self.name+' '+str(self.age)
        return a

std1 = Student('Abhijith',19)
a = std1.printf()
print(a)

        

