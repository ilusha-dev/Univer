import tkinter as tk
import random

# --- Logica Jocului ---
numar_secret = random.randint(1, 100)
incercari = 0

def verifica_presupunerea():
    global incercari, numar_secret
    try:
        presupunere = int(intrare_text.get())
        incercari += 1
        
        if presupunere == numar_secret:
            rezultat_label.config(text=f"Felicitări! Ai ghicit numărul {numar_secret} în {incercari} încercări!", fg="green")
            buton_ghiceste.config(state=tk.DISABLED) # Dezactivează butonul după câștig
        elif presupunere < numar_secret:
            rezultat_label.config(text="Prea mic! Mai încearcă.", fg="orange")
        else:
            rezultat_label.config(text="Prea mare! Mai încearcă.", fg="orange")
            
    except ValueError:
        rezultat_label.config(text="Introdu un număr valid întreg.", fg="red")

def reporneste_jocul():
    global numar_secret, incercari
    numar_secret = random.randint(1, 100)
    incercari = 0
    rezultat_label.config(text="Am generat un nou număr. Ghicește!", fg="black")
    intrare_text.delete(0, tk.END) # Golește câmpul de intrare
    buton_ghiceste.config(state=tk.NORMAL)

# --- Crearea Interfeței Grafice (GUI) ---

# 1. Creează fereastra principală
fereastra = tk.Tk()
fereastra.title("Jocul Ghicește Numărul")
fereastra.geometry("350x220") # Setează dimensiunea ferestrei

# 2. Adaugă elemente (widgets)
titlu_label = tk.Label(fereastra, text="Ghicește un număr (1-100)", font=("Helvetica", 14), pady=10)
titlu_label.pack() # Adaugă label-ul în fereastră

intrare_text = tk.Entry(fereastra, width=15, font=("Helvetica", 12))
intrare_text.pack(pady=5)

buton_ghiceste = tk.Button(fereastra, text="Ghicește", command=verifica_presupunerea, font=("Helvetica", 10))
buton_ghiceste.pack(pady=10)

rezultat_label = tk.Label(fereastra, text="Introdu prima ta presupunere!", font=("Helvetica", 10), pady=10)
rezultat_label.pack()

buton_repornire = tk.Button(fereastra, text="Joc Nou", command=reporneste_jocul, font=("Helvetica", 10))
buton_repornire.pack(pady=5)

# 3. Pornește bucla principală de evenimente (main event loop)
# Aceasta menține fereastra deschisă și activă
fereastra.mainloop()
