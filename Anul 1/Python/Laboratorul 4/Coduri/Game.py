import tkinter as tk
import random

# --- Inițializare colecții de date (Dicționar) și variabile globale ---

scoruri_meci = {
    "Jucător": 0,
    "Calculator": 0
}

# Variabilă globală pentru a urmări numărul rundei curente
numar_runda = 0

# --- Funcții logice ale jocului ---

def actualizeaza_text_buton():
    """
    Modifică textul butonului principal în funcție de numărul rundei curente.
    """
    global numar_runda
    if numar_runda == 0:
        buton_joaca.config(text="Joacă Prima Runda")
    else:
        buton_joaca.config(text="Joacă Runda Următoare")

def porneste_runda(scoruri: dict):
    """
    Simulează o singură rundă a jocului, actualizează scorurile 
    și verifică starea meciului.
    """
    global numar_runda
    numar_runda += 1
    actualizeaza_text_buton() # Actualizează textul imediat după incrementare

    nr_jucator = random.randint(1, 100)
    nr_calculator = random.randint(1, 100)

    # Determinarea câștigătorului rundei
    if nr_jucator > nr_calculator:
        castigator_runda = "Jucătorul"
        scoruri["Jucător"] += 1
    elif nr_calculator > nr_jucator:
        castigator_runda = "Calculatorul"
        scoruri["Calculator"] += 1
    else:
        castigator_runda = "Egalitate"

    # Actualizarea interfeței grafice cu rezultatele rundei
    rezultat_runda_text.config(text=f"Runda {numar_runda}: Jucător: {nr_jucator} | Calculator: {nr_calculator}")
    
    if castigator_runda == "Egalitate":
        mesaj_runda_text.config(text=f"Runda s-a terminat la egalitate!")
    else:
        mesaj_runda_text.config(text=f"Câștigătorul rundei: {castigator_runda}!")

    # Actualizarea scorului total în interfața grafică
    scor_jucator_label.config(text=f"Scor Jucător: {scoruri['Jucător']}")
    scor_calculator_label.config(text=f"Scor Calculator: {scoruri['Calculator']}")

    # Verificarea dacă meciul s-a încheiat (cineva a atins 3 victorii)
    if scoruri["Jucător"] >= 3 or scoruri["Calculator"] >= 3:
        determina_castigator_meci(scoruri)


def determina_castigator_meci(scoruri: dict):
    """
    Afișează câștigătorul final al meciului și dezactivează butonul de joc.
    """
    if scoruri["Jucător"] >= 3:
        castigator_meci = "Jucătorul"
    else:
        castigator_meci = "Calculatorul"
    
    mesaj_final_text.config(text=f"MECI TERMINAT! Câștigătorul final este: {castigator_meci}!", fg="green")
    
    # Dezactivarea butonului "Joacă" odată ce meciul s-a terminat
    buton_joaca.config(state=tk.DISABLED, text="Meci Terminat")


def resetare_joc(scoruri: dict):
    """
    Resetează starea jocului pentru o nouă partidă.
    """
    global numar_runda
    numar_runda = 0
    scoruri["Jucător"] = 0
    scoruri["Calculator"] = 0
    
    # Resetarea elementelor grafice
    scor_jucator_label.config(text=f"Scor Jucător: {scoruri['Jucător']}")
    scor_calculator_label.config(text=f"Scor Calculator: {scoruri['Calculator']}")
    rezultat_runda_text.config(text="Apasă 'Joacă Prima Runda' pentru a începe!")
    mesaj_runda_text.config(text="")
    mesaj_final_text.config(text="")
    
    # Reactivarea butonului și setarea textului inițial
    buton_joaca.config(state=tk.NORMAL)
    actualizeaza_text_buton() # Setează textul la "Joacă Prima Runda"


# --- Interfața Grafică (Tkinter) ---

fereastra = tk.Tk()
fereastra.title("Jocul Duel de Numere")
fereastra.geometry("420x320")

titlu_label = tk.Label(fereastra, text="Duel de Numere", font=("Helvetica", 16, "bold"))
titlu_label.pack(pady=10)

scor_jucator_label = tk.Label(fereastra, text=f"Scor Jucător: {scoruri_meci['Jucător']}", font=("Helvetica", 12))
scor_jucator_label.pack()

scor_calculator_label = tk.Label(fereastra, text=f"Scor Calculator: {scoruri_meci['Calculator']}", font=("Helvetica", 12))
scor_calculator_label.pack()

rezultat_runda_text = tk.Label(fereastra, text="Apasă 'Joacă Prima Runda' pentru a începe!", font=("Helvetica", 10), pady=10)
rezultat_runda_text.pack()

mesaj_runda_text = tk.Label(fereastra, text="", font=("Helvetica", 11, "italic"), fg="blue")
mesaj_runda_text.pack()

mesaj_final_text = tk.Label(fereastra, text="", font=("Helvetica", 13, "bold"))
mesaj_final_text.pack(pady=15)


# Butonul principal pentru a juca o rundă nouă
buton_joaca = tk.Button(fereastra, command=lambda: porneste_runda(scoruri_meci), width=25)
# Setăm textul inițial la încărcarea interfeței:
actualizeaza_text_buton() 
buton_joaca.pack(pady=5)


# Buton pentru a reseta jocul
buton_reset = tk.Button(fereastra, text="Resetare Joc Nou", command=lambda: resetare_joc(scoruri_meci))
buton_reset.pack(pady=5)


# Rularea buclei principale a interfeței grafice
fereastra.mainloop()
