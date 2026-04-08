import math

a = 314
b = 3.14
c = "314abc"
print("Type of a: ",type(a),"\n","Type of b: ",type(b),"\n","Type of c: ",type(c),"\n")

#name = input("Enter your name: ")
name = "Ilie"
print(f"Hello, {name}!")

print("1. Să se execute în consola Python toate expresiile, să se explice rezultatele:\n") 
print("a) 7 / 9 =", 7 / 9)
print("b) 3.3 + 1.7 =", 3.3+1.7)
print("c) 9-7 =", 9-7)
print("d) 10+103 =", 10+103)
print("e) 0+0.1 =", 0+0.1)
print("f) 7*1 =", 7*1)
print("g) 7.7/3 =", 7.7/3)
print("h) 12*2.0 =", 12*2.0)
print("i) 7.3-2.3 =", 7.3-2.3)
print("j) 7 % 3  =", 7 % 3)
print("k) 7 % -2 =", 7 % -2)
print("l) 2% 5 =", 2% 5)
print("m) -2% 5 =", -2% 5)
print("n) -8 % 2 =", -8 % 2)
print("o) -8%-2 =", -8%-2)

print("\n 2. Sa se afișeze rezultatul efecutării următorului cod:\n")
print("a) bool(-30) =",bool(-30) )  #este true fiind ca orice numar nenul este true
print("b) bool(0.2) =",bool(0.2))
print("c) bool(0) =",bool(0))
#print("d) bool(s) =",bool(s))   #error, s trebuie sa fie declarata
print("e) bool(None) =",bool(None))
print("f) bool(bool) =",bool(bool))

print("\n 3. Să se verifice tipul și valoarea următoarei expresii: \n")
print("a) type(7.3e+8) =",type(7.3e+8))
print("b) type(8+7.0+24) =",type(8+7.0+24))
print("c) type(None) =",type(None))
print("d) type('float') =",type('float'))
print("e) type(7+3j) =",type(7+3j))
#print("f) type(8+5i)",type(8+5i))   #error, pentru numere complexe pythonul foloseste j

print("\n 4. Să se calculeze valoarea variabilei întregi z pentru a=45 și b=6. \n")
a=45
b=6
z=b+a%b
print("z =",z)
z=b-a%b
print("z =",z)
z=b+a%-b
print("z =",z)
z=b-a%-b
print("z =",z)
z=a-a//b
print("z =",z)
z=a//b 
b=a//b
print("z =",z,"b = ",b)
b=6
b=a//b+b
z=a//b
print("z =",z, "b =",b)
b=6
b=a%b+2
z=a%b+a
print("z =",z, "b =",b)
b=6
b=a//b
z=a%(b+2)
print("z =",z, "b =",b)
b=6
b=a%b 
z=a//(b+2)
print("z =",z, "b =",b)

print("\n 5. Să se compare și să se explice valorile expresiilor obținute:")
print(18.5/2.5) #expresia este float, se primeste 7.4
print(int(18.5)/int(2.5)) #numaratorul si numitorul se convertesc in int, de aceeia se primeste 18/2 ceea ce e 9
print(int(18.5/2.5)) #numerele sunt in float, iar dupa, rezultatul se converteste in int prin lipsa

print("\n 6. Să se anticipeze rezultatul fiecăreia dintre următoarele instrucțiuni, apoi să fie verificate în interpretorul Python.")
print(str(8) * int('5')) #88888
print(int("8") + float("7.3")) #15.3
#print(str(6) * float("7.3")) #error ca stringu nu se inmulteste cu float
print(str(18/4) * 3) #4.5 de 3 ori

print("\n 7. Să se scrie o instrucțiune care afișează valorile variabilelor a=5 și b =6 în următorul format.")
a=5
b=6
print(f"{a}+{b}=?")
print(f"({a})({b})")
print(f"a={a}; b={b};")
print(f"Raspuns: ({5}; {6})")

print("\n 8. Să se scrie un program care ia de la tastatură două valori întregi A și B, și calculează valoarea lui Z:\n Z =(A**2 + B**2 ) (A - B)**2")
A = int(input("A = "))
B = int(input("B = "))
print(f"Z = ({A}^2 + {B}^2)({A}-{B})^2 =", (pow(A,2) + pow(B,2))*pow(A-B,2))

print("\nExercițiul cu variante (Eu sunt 24 dupa lista din catalog) \nVar 24")
a = 0.7
d = 3.6
q = abs(math.sin(pow(a, 2) + d) - math.sqrt(d))
b = math.exp(q) / math.exp(math.sqrt(pow(a, 2) + (pow(d, 2))) + 1) + math.log(d + 2)
print(f"b = {round(b,5)}")
