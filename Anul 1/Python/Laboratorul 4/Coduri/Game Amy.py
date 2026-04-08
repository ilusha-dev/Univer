import tkinter as tk
import random

# --- Inițializare colecții de date (Dicționar) și variabile globale ---

scoruri_joc2 = {
    "Victorii Jucător": 0,
    "Victorii Calculator": 0
}

numar_runda_doi = 0
NUMAR_MAXIM_VICTORII = 3

# --- Funcții logice ale jocului ---

def actualizeaza_text_buton_doi():
    """
    Modifică textul butonului principal în funcție de numărul rundei curente.
    """
    global numar_runda_doi
    if numar_runda_doi == 0:
        buton_ghiceste_par.config(text="Alege PAR (Prima Runda)")
        buton_ghiceste_impar.config(text="Alege IMPAR (Prima Runda)")
    else:
        buton_ghiceste_par.config(text="Alege PAR")
        buton_ghiceste_impar.config(text="Alege IMPAR")


def determina_castigator_meci_doi():
    """
    Afișează câștigătorul final al meciului și dezactivează butoanele de joc.
    """
    if scoruri_joc2["Victorii Jucător"] >= NUMAR_MAXIM_VICTORII:
        castigator_meci = "Jucătorul"
        culoare = "green"
    elif scoruri_joc2["Victorii Calculator"] >= NUMAR_MAXIM_VICTORII:
        # Dacă jucătorul nu a ajuns la 3, dar calculatorul (prin eșecurile jucătorului) a ajuns
        castigator_meci = "Calculatorul"
        culoare = "red"
    else:
        return # Meciul nu s-a terminat încă

    mesaj_final_doi_text.config(text=f"MECI TERMINAT! Câștigătorul final este: {castigator_meci}!", fg=culoare)
    
    # Dezactivarea butoanelor odată ce meciul s-a terminat
    buton_ghiceste_par.config(state=tk.DISABLED)
    buton_ghiceste_impar.config(state=tk.DISABLED)


def par_sau_impar(alegere_jucator: str):
    """
    Funcția principală a jocului. Generează un număr, compară cu alegerea 
    utilizatorului și actualizează starea jocului.
    :param alegere_jucator: 'Par' sau 'Impar'
    """
    global numar_runda_doi
    numar_runda_doi += 1
    actualizeaza_text_buton_doi() 

    numar_generat = random.randint(1, 100)
    este_par = (numar_generat % 2 == 0)
    rezultat_real = "Par" if este_par else "Impar"

    # Verificare logică
    if alegere_jucator == rezultat_real:
        mesaj = f"Corect! Numărul {numar_generat} este {rezultat_real}. Ai ghicit!"
        scoruri_joc2["Victorii Jucător"] += 1
        culoare_text_runda = "blue"
    else:
        mesaj = f"Greșit! Numărul {numar_generat} este {rezultat_real}. Calculatorul câștigă punctul."
        # Putem ține scorul calculatorului ca număr de greșeli ale jucătorului
        scoruri_joc2["Victorii Calculator"] += 1 
        culoare_text_runda = "purple"

    # Actualizare Interfață Grafică
    rezultat_runda_doi_text.config(text=f"Runda {numar_runda_doi}: {mesaj}", fg=culoare_text_runda)
    scor_jucator_doi_label.config(text=f"Scor Jucător (Ghiciri corecte): {scoruri_joc2['Victorii Jucător']}")
    
    # Verificare final meci
    determina_castigator_meci_doi()


def resetare_joc_doi():
    """
    Resetează starea jocului pentru o nouă partidă.
    """
    global numar_runda_doi
    numar_runda_doi = 0
    scoruri_joc2["Victorii Jucător"] = 0
    scoruri_joc2["Victorii Calculator"] = 0
    
    # Resetarea elementelor grafice
    scor_jucator_doi_label.config(text=f"Scor Jucător (Ghiciri corecte): {scoruri_joc2['Victorii Jucător']}")
    rezultat_runda_doi_text.config(text="Alege 'Par' sau 'Impar' pentru a începe prima rundă!")
    mesaj_final_doi_text.config(text="")
    
    # Reactivarea butoanelor și setarea textului inițial
    buton_ghiceste_par.config(state=tk.NORMAL)
    buton_ghiceste_impar.config(state=tk.NORMAL)
    actualizeaza_text_buton_doi() 


# --- Interfața Grafică (Tkinter) ---

fereastra_doi = tk.Tk()
fereastra_doi.title("Jocul Par sau Impar")
fereastra_doi.geometry("450x300")

titlu_doi_label = tk.Label(fereastra_doi, text="Par sau Impar?", font=("Helvetica", 16, "bold"))
titlu_doi_label.pack(pady=10)

instructiuni_label = tk.Label(fereastra_doi, text="Ghicește dacă numărul generat (1-100) va fi par sau impar.\nPrimul care ajunge la 3 victorii câștigă meciul.", justify=tk.CENTER)
instructiuni_label.pack(pady=5)

scor_jucator_doi_label = tk.Label(fereastra_doi, text=f"Scor Jucător (Ghiciri corecte): {scoruri_joc2['Victorii Jucător']}", font=("Helvetica", 12))
scor_jucator_doi_label.pack(pady=10)

# Butoanele de acțiune (utilizatorul alege)
frame_butoane = tk.Frame(fereastra_doi)
frame_butoane.pack(pady=10)

# Folosim lambda pentru a pasa parametrul 'Par' sau 'Impar' funcției par_sau_impar
buton_ghiceste_par = tk.Button(frame_butoane, command=lambda: par_sau_impar('Par'), width=20, bg='lightblue')
buton_ghiceste_impar = tk.Button(frame_butoane, command=lambda: par_sau_impar('Impar'), width=20, bg='lightgreen')

# Setăm textul inițial la încărcarea interfeței
actualizeaza_text_buton_doi() 

buton_ghiceste_par.pack(side=tk.LEFT, padx=10)
buton_ghiceste_impar.pack(side=tk.RIGHT, padx=10)


# Etichetă pentru afișarea rezultatului rundei
rezultat_runda_doi_text = tk.Label(fereastra_doi, text="Alege 'Par' sau 'Impar' pentru a începe prima rundă!", font=("Helvetica", 10, "italic"), pady=10)
rezultat_runda_doi_text.pack()

# Etichetă pentru afișarea câștigătorului final al meciului
mesaj_final_doi_text = tk.Label(fereastra_doi, text="", font=("Helvetica", 13, "bold"))
mesaj_final_doi_text.pack(pady=15)


# Buton pentru a reseta jocul
buton_reset_doi = tk.Button(fereastra_doi, text="Resetare Joc Nou", command=lambda: resetare_joc_doi())
buton_reset_doi.pack(pady=5)


# Rularea buclei principale a interfeței grafice
fereastra_doi.mainloop()
