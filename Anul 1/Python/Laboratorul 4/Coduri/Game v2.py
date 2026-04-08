import tkinter as tk
import random

# =====================================================================
# METODA 1: FOLOSIND UN DICTIONAR (CEL MAI RECOMANDAT)
# =====================================================================

def ruleaza_joc_dictionar():
    scoruri = {"Jucător": 0, "Calculator": 0}
    runda = 0
    NUMAR_MAXIM_VICTORII = 3

    def porneste_runda():
        nonlocal runda
        if scoruri["Jucător"] >= NUMAR_MAXIM_VICTORII or scoruri["Calculator"] >= NUMAR_MAXIM_VICTORII: return
        runda += 1
        
        nr_j = random.randint(1, 100)
        nr_c = random.randint(1, 100)
        
        if nr_j > nr_c:
            castigator = "Jucătorul"
            scoruri["Jucător"] += 1
        elif nr_c > nr_j:
            castigator = "Calculatorul"
            scoruri["Calculator"] += 1
        else:
            castigator = "Egalitate"
        
        rezultat_runda_text.config(text=f"Runda {runda}: Jucător: {nr_j} | Calculator: {nr_c}")
        mesaj_runda_text.config(text=f"Câștigătorul: {castigator}!" if castigator != "Egalitate" else "Rundă egală!")
        scor_jucator_label.config(text=f"Scor Jucător: {scoruri['Jucător']}")
        scor_calculator_label.config(text=f"Scor Calculator: {scoruri['Calculator']}") 

        if scoruri["Jucător"] >= NUMAR_MAXIM_VICTORII or scoruri["Calculator"] >= NUMAR_MAXIM_VICTORII:
            castigator_meci = "Jucătorul" if scoruri["Jucător"] >= NUMAR_MAXIM_VICTORII else "Calculatorul"
            mesaj_final_text.config(text=f"MECI TERMINAT! Câștigătorul: {castigator_meci}!", fg="green")
            buton_joaca.config(state=tk.DISABLED, text="Meci Terminat")
        else:
            buton_joaca.config(text="Joacă Runda Următoare" if runda > 0 else "Joacă Prima Runda")

    def resetare_joc():
        nonlocal runda
        runda = 0
        scoruri["Jucător"] = 0
        scoruri["Calculator"] = 0
        rezultat_runda_text.config(text="Apasă 'Joacă' pentru a începe!")
        mesaj_runda_text.config(text="")
        mesaj_final_text.config(text="")
        scor_jucator_label.config(text=f"Scor Jucător: 0")
        scor_calculator_label.config(text=f"Scor Calculator: 0")
        buton_joaca.config(state=tk.NORMAL, text="Joacă Prima Runda")

    # UI Tkinter: Linii consolidate pentru optimizare vizuală
    fereastra = tk.Tk(); fereastra.title("Jocul Duel de Numere (Dict)"); fereastra.geometry("400x300")
    tk.Label(fereastra, text="Duel de Numere", font=("Helvetica", 16, "bold")).pack(pady=10)
    scor_jucator_label = tk.Label(fereastra, text=f"Scor Jucător: 0", font=("Helvetica", 12)); scor_jucator_label.pack()
    scor_calculator_label = tk.Label(fereastra, text=f"Scor Calculator: 0", font=("Helvetica", 12)); scor_calculator_label.pack()
    rezultat_runda_text = tk.Label(fereastra, text="Apasă 'Joacă' pentru a începe!", font=("Helvetica", 10), pady=10); rezultat_runda_text.pack()
    mesaj_runda_text = tk.Label(fereastra, text="", font=("Helvetica", 11, "italic"), fg="blue"); mesaj_runda_text.pack()
    mesaj_final_text = tk.Label(fereastra, text="", font=("Helvetica", 13, "bold")); mesaj_final_text.pack(pady=15)
    buton_joaca = tk.Button(fereastra, text="Joacă Prima Runda", command=porneste_runda, width=25); buton_joaca.pack(pady=5)
    tk.Button(fereastra, text="Resetare Joc Nou", command=resetare_joc).pack(pady=5)
    
    fereastra.mainloop()

# =====================================================================
# METODA 2: FOLOSIND O LISTA
# =====================================================================

def ruleaza_joc_lista():
    scoruri = (0, 0)
    runda = 0
    NUMAR_MAXIM_VICTORII = 3
    IJ = 0; IC = 1

    def porneste_runda_list():
        nonlocal runda
        if scoruri[IJ] >= NUMAR_MAXIM_VICTORII or scoruri[IC] >= NUMAR_MAXIM_VICTORII: return
        runda += 1
        nr_j = random.randint(1, 100)
        nr_c = random.randint(1, 100)
        
        if nr_j > nr_c:
            castigator = "Jucătorul"
            scoruri[IJ] += 1
        elif nr_c > nr_j:
            castigator = "Calculatorul"
            scoruri[IC] += 1
        else:
            castigator = "Egalitate"

        rezultat_runda_text.config(text=f"Runda {runda}: Jucător: {nr_j} | Calculator: {nr_c}")
        mesaj_runda_text.config(text=f"Câștigătorul: {castigator}!" if castigator != "Egalitate" else "Rundă egală!")
        scor_jucator_label.config(text=f"Scor Jucător: {scoruri[IJ]}") # Afișare Listă prin index
        scor_calculator_label.config(text=f"Scor Calculator: {scoruri[IC]}") # Afișare Listă prin index

        if scoruri[IJ] >= NUMAR_MAXIM_VICTORII or scoruri[IC] >= NUMAR_MAXIM_VICTORII:
            castigator_meci = "Jucătorul" if scoruri[IJ] >= NUMAR_MAXIM_VICTORII else "Calculatorul"
            mesaj_final_text.config(text=f"MECI TERMINAT! Câștigătorul: {castigator_meci}!", fg="green")
            buton_joaca.config(state=tk.DISABLED, text="Meci Terminat")
        else:
            buton_joaca.config(text="Joacă Runda Următoare" if runda > 0 else "Joacă Prima Runda")

    def resetare_joc_list():
        nonlocal runda
        runda = 0
        scoruri[IJ] = 0
        scoruri[IC] = 0
        # ... (Logica UI similară cu Metoda 1, folosind scoruri[IJ/IC]) ...

    # UI Tkinter pentru Metoda 2 (Listă)
    fereastra = tk.Tk(); fereastra.title("Jocul Duel de Numere (List)"); fereastra.geometry("400x300")
    tk.Label(fereastra, text="Duel de Numere", font=("Helvetica", 16, "bold")).pack(pady=10)
    scor_jucator_label = tk.Label(fereastra, text=f"Scor Jucător: 0", font=("Helvetica", 12)); scor_jucator_label.pack()
    scor_calculator_label = tk.Label(fereastra, text=f"Scor Calculator: 0", font=("Helvetica", 12)); scor_calculator_label.pack()
    rezultat_runda_text = tk.Label(fereastra, text="Apasă 'Joacă' pentru a începe!", font=("Helvetica", 10), pady=10); rezultat_runda_text.pack()
    mesaj_runda_text = tk.Label(fereastra, text="", font=("Helvetica", 11, "italic"), fg="blue"); mesaj_runda_text.pack()
    mesaj_final_text = tk.Label(fereastra, text="", font=("Helvetica", 13, "bold")); mesaj_final_text.pack(pady=15)
    buton_joaca = tk.Button(fereastra, text="Joacă Prima Runda", command=porneste_runda_list, width=25); buton_joaca.pack(pady=5)
    tk.Button(fereastra, text="Resetare Joc Nou", command=resetare_joc_list).pack(pady=5)

    # fereastra.mainloop()

# =====================================================================
# METODA 3: FOLOSIND UN TUPLU
# =====================================================================

def ruleaza_joc_tuplu():
    scoruri = (0, 0)
    runda = 0
    NUMAR_MAXIM_VICTORII = 3
    IJ = 0; IC = 1

    def porneste_runda_tuple():
        nonlocal runda, scoruri # Necesită nonlocal pentru tuplu și runda
        if scoruri[IJ] >= NUMAR_MAXIM_VICTORII or scoruri[IC] >= NUMAR_MAXIM_VICTORII: return
        runda += 1
        nr_j = random.randint(1, 100)
        nr_c = random.randint(1, 100)
        
        j_score, c_score = scoruri
        if nr_j > nr_c:
            castigator = "Jucătorul"
            j_score += 1
        elif nr_c > nr_j:
            castigator = "Calculatorul"
            c_score += 1
        else:
            castigator = "Egalitate"
        scoruri = (j_score, c_score) # Reasignare globală/nonlocală cu noul tuplu

        rezultat_runda_text.config(text=f"Runda {runda}: Jucător: {nr_j} | Calculator: {nr_c}")
        mesaj_runda_text.config(text=f"Câștigătorul: {castigator}!" if castigator != "Egalitate" else "Rundă egală!")
        scor_jucator_label.config(text=f"Scor Jucător: {scoruri[IJ]}")
        scor_calculator_label.config(text=f"Scor Calculator: {scoruri[IC]}")

        if scoruri[IJ] >= NUMAR_MAXIM_VICTORII or scoruri[IC] >= NUMAR_MAXIM_VICTORII:
            castigator_meci = "Jucătorul" if scoruri[IJ] >= NUMAR_MAXIM_VICTORII else "Calculatorul"
            mesaj_final_text.config(text=f"MECI TERMINAT! Câștigătorul: {castigator_meci}!", fg="green")
            buton_joaca.config(state=tk.DISABLED, text="Meci Terminat")
        else:
            buton_joaca.config(text="Joacă Runda Următoare" if runda > 0 else "Joacă Prima Runda")

    def resetare_joc_tuple():
        nonlocal runda, scoruri
        runda = 0
        scoruri = (0, 0) # Resetare prin reasignare
        # ... (Logica UI similară cu Metoda 1) ...

    # UI Tkinter pentru Metoda 3 (Tuplu)
    fereastra = tk.Tk(); fereastra.title("Jocul Duel de Numere (Tuple)"); fereastra.geometry("400x300")
    tk.Label(fereastra, text="Duel de Numere", font=("Helvetica", 16, "bold")).pack(pady=10)
    scor_jucator_label = tk.Label(fereastra, text=f"Scor Jucător: 0", font=("Helvetica", 12)); scor_jucator_label.pack()
    scor_calculator_label = tk.Label(fereastra, text=f"Scor Calculator: 0", font=("Helvetica", 12)); scor_calculator_label.pack()
    rezultat_runda_text = tk.Label(fereastra, text="Apasă 'Joacă' pentru a începe!", font=("Helvetica", 10), pady=10); rezultat_runda_text.pack()
    mesaj_runda_text = tk.Label(fereastra, text="", font=("Helvetica", 11, "italic"), fg="blue"); mesaj_runda_text.pack()
    mesaj_final_text = tk.Label(fereastra, text="", font=("Helvetica", 13, "bold")); mesaj_final_text.pack(pady=15)
    buton_joaca = tk.Button(fereastra, text="Joacă Prima Runda", command=porneste_runda_tuple, width=25); buton_joaca.pack(pady=5)
    tk.Button(fereastra, text="Resetare Joc Nou", command=resetare_joc_tuple).pack(pady=5)
    
    # fereastra.mainloop()

# =====================================================================
# METODA 4: FOLOSIND O CLASA (OOP)
# =====================================================================

class GameStateDuel:
    def __init__(self):
        self.player_score = 0
        self.computer_score = 0
        self.round_num = 0
        self.NUMAR_MAXIM_VICTORII = 3

def ruleaza_joc_clasa():
    s = stare_joc_oop = GameStateDuel()

    def porneste_runda_oop():
        if s.player_score >= s.NUMAR_MAXIM_VICTORII or s.computer_score >= s.NUMAR_MAXIM_VICTORII: return
        s.round_num += 1
        nr_j = random.randint(1, 100)
        nr_c = random.randint(1, 100)
        
        if nr_j > nr_c:
            castigator = "Jucătorul"
            s.player_score += 1
        elif nr_c > nr_j:
            castigator = "Calculatorul"
            s.computer_score += 1 
        else:
            castigator = "Egalitate"

        rezultat_runda_text.config(text=f"Runda {s.round_num}: Jucător: {nr_j} | Calculator: {nr_c}")
        mesaj_runda_text.config(text=f"Câștigătorul: {castigator}!" if castigator != "Egalitate" else "Rundă egală!")
        scor_jucator_label.config(text=f"Scor Jucător: {s.player_score}") # Afișare Clasă prin atribut
        scor_calculator_label.config(text=f"Scor Calculator: {s.computer_score}") # Afișare Clasă prin atribut

        if s.player_score >= s.NUMAR_MAXIM_VICTORII or s.computer_score >= s.NUMAR_MAXIM_VICTORII:
            castigator_meci = "Jucătorul" if s.player_score >= s.NUMAR_MAXIM_VICTORII else "Calculatorul"
            mesaj_final_text.config(text=f"MECI TERMINAT! Câștigătorul: {castigator_meci}!", fg="green")
            buton_joaca.config(state=tk.DISABLED, text="Meci Terminat")
        else:
            buton_joaca.config(text="Joacă Runda Următoare" if s.round_num > 0 else "Joacă Prima Runda")

    def resetare_joc_oop():
        s.round_num = 0
        s.player_score = 0
        s.computer_score = 0
        # ... (Logica UI similară cu Metoda 1) ...

    # UI Tkinter pentru Metoda 4 (Clasă)
    fereastra = tk.Tk(); fereastra.title("Jocul Duel de Numere (OOP)"); fereastra.geometry("400x300")
    tk.Label(fereastra, text="Duel de Numere", font=("Helvetica", 16, "bold")).pack(pady=10)
    scor_jucator_label = tk.Label(fereastra, text=f"Scor Jucător: 0", font=("Helvetica", 12)); scor_jucator_label.pack()
    scor_calculator_label = tk.Label(fereastra, text=f"Scor Calculator: 0", font=("Helvetica", 12)); scor_calculator_label.pack()
    rezultat_runda_text = tk.Label(fereastra, text="Apasă 'Joacă' pentru a începe!", font=("Helvetica", 10), pady=10); rezultat_runda_text.pack()
    mesaj_runda_text = tk.Label(fereastra, text="", font=("Helvetica", 11, "italic"), fg="blue"); mesaj_runda_text.pack()
    mesaj_final_text = tk.Label(fereastra, text="", font=("Helvetica", 13, "bold")); mesaj_final_text.pack(pady=15)
    buton_joaca = tk.Button(fereastra, text="Joacă Prima Runda", command=porneste_runda_oop, width=25); buton_joaca.pack(pady=5)
    tk.Button(fereastra, text="Resetare Joc Nou", command=resetare_joc_oop).pack(pady=5)
    
    # fereastra.mainloop()

# Punctul de intrare al scriptului:
if __name__ == "__main__":
    
    ruleaza_joc_dictionar()
    # ruleaza_joc_lista()
    # ruleaza_joc_tuplu()
    # ruleaza_joc_clasa()
