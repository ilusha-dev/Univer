import tkinter as tk
import random

# =====================================================================
# METODA 1: FOLOSIND UN DICTIONAR (CEL MAI RECOMANDAT)
# =====================================================================

def ruleaza_joc_dictionar():
    # Variabile specifice metodei 1
    scoruri = {"Jucător": 0, "Calculator": 0}
    runda = 0
    NUMAR_MAXIM_VICTORII = 3

    def porneste_runda(alegere_jucator: str):
        nonlocal runda # Folosim nonlocal pentru a modifica variabila runda din scope-ul superior
        if scoruri["Jucător"] >= NUMAR_MAXIM_VICTORII or scoruri["Calculator"] >= NUMAR_MAXIM_VICTORII: return
        runda += 1
        numar_generat = random.randint(1, 100)
        rezultat_real = "Par" if numar_generat % 2 == 0 else "Impar"
        
        if alegere_jucator == rezultat_real:
            mesaj = f"Corect! {numar_generat} este {rezultat_real}."
            scoruri["Jucător"] += 1
        else:
            mesaj = f"Greșit! {numar_generat} este {rezultat_real}."
            scoruri["Calculator"] += 1

        rezultat_runda_doi_text.config(text=f"Runda {runda}: {mesaj}")
        scor_jucator_doi_label.config(text=f"Scor Jucător: {scoruri['Jucător']}")

        if scoruri["Jucător"] >= NUMAR_MAXIM_VICTORII or scoruri["Calculator"] >= NUMAR_MAXIM_VICTORII:
            castigator_meci = "Jucătorul" if scoruri["Jucător"] >= NUMAR_MAXIM_VICTORII else "Calculatorul"
            mesaj_final_doi_text.config(text=f"MECI TERMINAT! Câștigătorul: {castigator_meci}!", fg="green")
            buton_ghiceste_par.config(state=tk.DISABLED)
            buton_ghiceste_impar.config(state=tk.DISABLED)
        elif runda == 1:
            buton_ghiceste_par.config(text="Alege PAR")
            buton_ghiceste_impar.config(text="Alege IMPAR")

    def resetare_joc():
        nonlocal runda
        runda = 0
        scoruri["Jucător"] = 0
        scoruri["Calculator"] = 0
        scor_jucator_doi_label.config(text=f"Scor Jucător: 0")
        rezultat_runda_doi_text.config(text="Alege 'Par' sau 'Impar' pentru a începe prima rundă!")
        mesaj_final_doi_text.config(text="")
        buton_ghiceste_par.config(state=tk.NORMAL, text="Alege PAR (Prima Runda)")
        buton_ghiceste_impar.config(state=tk.NORMAL, text="Alege IMPAR (Prima Runda)")

    # UI Tkinter pentru Metoda 1 (Dicționar)
    fereastra_doi = tk.Tk(); fereastra_doi.title("Jocul Par sau Impar (Dict)"); fereastra_doi.geometry("450x300")
    tk.Label(fereastra_doi, text="Par sau Impar?", font=("Helvetica", 16, "bold")).pack(pady=10)
    tk.Label(fereastra_doi, text="Primul la 3 victorii câștigă.", justify=tk.CENTER).pack(pady=5)
    scor_jucator_doi_label = tk.Label(fereastra_doi, text=f"Scor Jucător: 0", font=("Helvetica", 12)); scor_jucator_doi_label.pack(pady=10)
    frame_butoane = tk.Frame(fereastra_doi); frame_butoane.pack(pady=10)
    buton_ghiceste_par = tk.Button(frame_butoane, text="Alege PAR (Prima Runda)", command=lambda: porneste_runda('Par'), width=25, bg='lightblue')
    buton_ghiceste_impar = tk.Button(frame_butoane, text="Alege IMPAR (Prima Runda)", command=lambda: porneste_runda('Impar'), width=25, bg='lightgreen')
    buton_ghiceste_par.pack(side=tk.LEFT, padx=10); buton_ghiceste_impar.pack(side=tk.RIGHT, padx=10)
    rezultat_runda_doi_text = tk.Label(fereastra_doi, text="Alege 'Par' sau 'Impar' pentru a începe prima rundă!", font=("Helvetica", 10, "italic"), pady=10); rezultat_runda_doi_text.pack()
    mesaj_final_doi_text = tk.Label(fereastra_doi, text="", font=("Helvetica", 13, "bold")); mesaj_final_doi_text.pack(pady=15)
    tk.Button(fereastra_doi, text="Resetare Joc Nou", command=resetare_joc).pack(pady=5)
    fereastra_doi.mainloop()

# =====================================================================
# METODA 2: FOLOSIND O LISTA
# =====================================================================

def ruleaza_joc_lista():
    # Variabile specifice metodei 2
    scoruri = (0, 0) # [ScorJucator, ScorCalculator]
    runda = 0
    NUMAR_MAXIM_VICTORII = 3
    IJ = 0; IC = 1

    def porneste_runda_list(alegere_jucator: str):
        nonlocal runda
        if scoruri[IJ] >= NUMAR_MAXIM_VICTORII or scoruri[IC] >= NUMAR_MAXIM_VICTORII: return
        runda += 1
        numar_generat = random.randint(1, 100)
        rezultat_real = "Par" if numar_generat % 2 == 0 else "Impar"
        if alegere_jucator == rezultat_real:
            scoruri[IJ] += 1
        else:
            scoruri[IC] += 1
        # ... (Logica UI similară cu Metoda 1, folosind scoruri[IJ]) ...
        # Notă: Codul complet ar trebui inserat aici.

    # ... (Funcția resetare_joc_list ar trebui inserată aici) ...

    # UI Tkinter pentru Metoda 2 (Listă)
    # ... (Codul UI similar cu Metoda 1) ...
    # fereastra_doi.mainloop() # Comentat implicit

# =====================================================================
# METODA 3: FOLOSIND UN TUPLU
# =====================================================================

def ruleaza_joc_tuplu():
    # Variabile specifice metodei 3
    scoruri = (0, 0)
    runda = 0
    NUMAR_MAXIM_VICTORII = 3
    IJ = 0; IC = 1

    def porneste_runda_tuple(alegere_jucator: str):
        nonlocal runda, scoruri # Necesită nonlocal pentru tuplu și runda
        if scoruri[IJ] >= NUMAR_MAXIM_VICTORII or scoruri[IC] >= NUMAR_MAXIM_VICTORII: return
        runda += 1
        numar_generat = random.randint(1, 100)
        rezultat_real = "Par" if numar_generat % 2 == 0 else "Impar"
        j_score, c_score = scoruri
        if alegere_jucator == rezultat_real:
            j_score += 1
        else:
            c_score += 1
        scoruri = (j_score, c_score) # Reasignare
        # ... (Logica UI similară cu Metoda 1, folosind scoruri[IJ]) ...
        # Notă: Codul complet ar trebui inserat aici.

    # ... (Funcția resetare_joc_tuple ar trebui inserată aici) ...

    # UI Tkinter pentru Metoda 3 (Tuplu)
    # ... (Codul UI similar cu Metoda 1) ...
    # fereastra_doi.mainloop() # Comentat implicit

# =====================================================================
# METODA 4: FOLOSIND O CLASA (OOP)
# =====================================================================

class GameStateParImpar:
    def __init__(self):
        self.player_wins = 0
        self.computer_wins = 0
        self.round_num = 0
        self.NUMAR_MAXIM_VICTORII = 3

def ruleaza_joc_clasa():
    # Variabile specifice metodei 4
    s = stare_joc_pi_oop = GameStateParImpar()

    def porneste_runda_oop(alegere_jucator: str):
        if s.player_wins >= s.NUMAR_MAXIM_VICTORII or s.computer_wins >= s.NUMAR_MAXIM_VICTORII: return
        s.round_num += 1
        numar_generat = random.randint(1, 100)
        rezultat_real = "Par" if numar_generat % 2 == 0 else "Impar"
        if alegere_jucator == rezultat_real:
            s.player_wins += 1
        else:
            s.computer_wins += 1
        # ... (Logica UI similară cu Metoda 1, folosind s.player_wins) ...
        # Notă: Codul complet ar trebui inserat aici.

    # ... (Funcția resetare_joc_oop ar trebui inserată aici) ...

    # UI Tkinter pentru Metoda 4 (Clasă)
    # ... (Codul UI similar cu Metoda 1) ...
    # fereastra_doi.mainloop() # Comentat implicit


# =====================================================================
# FUNCTIE PRINCIPALA PENTRU A ALEGE CE METODA RULAM
# =====================================================================

# Punctul de intrare al scriptului:
if __name__ == "__main__":
    # Apelăm direct prima metodă (Dicționar) ca metodă implicită de rulare.
    print("Rularea Jocului 'Par sau Impar' folosind Metoda 1 (Dicționar).")
    print("Pentru a rula o altă metodă, decomentați apelul mainloop() din funcția dorită.")
    ruleaza_joc_dictionar()
