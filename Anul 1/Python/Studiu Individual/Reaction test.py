import tkinter as tk
import random
import time

class ReactionGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Joc de Reacție")
        self.root.geometry("400x300")
        
        self.running = False
        self.start_time = 0
        self.reaction_times = []
        
        self.label = tk.Label(root, text="Așteaptă să devină verde, apoi apasă butonul!", font=("Helvetica", 16), bg="red")
        self.label.pack(pady=20, fill=tk.BOTH, expand=True)

        self.start_button = tk.Button(root, text="START", command=self.start_game, font=("Helvetica", 14))
        self.start_button.pack(pady=10)

        self.result_label = tk.Label(root, text="", font=("Helvetica", 12))
        self.result_label.pack(pady=10)

    def start_game(self):
        if not self.running:
            self.running = True
            self.start_button.config(state=tk.DISABLED)
            self.label.config(text="Așteaptă...", bg="red")
            self.result_label.config(text="")
            # Așteaptă un timp aleatoriu între 2 și 5 secunde
            delay = random.randint(2000, 5000)
            self.root.after(delay, self.change_to_green)

    def change_to_green(self):
        if self.running:
            self.label.config(text="APASĂ ACUM!", bg="green")
            self.start_time = time.time()

    def stop_game(self, event=None):
        if self.running:
            # Verifică dacă utilizatorul a apăsat pe roșu (a trișat)
            if self.label.cget("bg") == "red":
                 self.result_label.config(text="Ai trișat! Așteaptă verde.", fg="orange")
                 self.reset_game()
                 return
            
            if self.label.cget("bg") == "green":
                end_time = time.time()
                reaction_time = round((end_time - self.start_time) * 1000)
                self.reaction_times.append(reaction_time)
                
                avg_time = sum(self.reaction_times) / len(self.reaction_times)
                
                self.result_label.config(
                    text=f"Timpul tău: {reaction_time} ms.\nMedia (după {len(self.reaction_times)} încercări): {round(avg_time)} ms.",
                    fg="blue"
                )
                self.reset_game()

    def reset_game(self):
        self.running = False
        self.start_button.config(state=tk.NORMAL, text="Începe o nouă rundă")
        self.label.config(text="Gata pentru runda următoare?", bg="lightgray")


# Rulare aplicație
if __name__ == "__main__":
    root = tk.Tk()
    game = ReactionGame(root)
    # Legăm evenimentul de click pe label de funcția stop_game
    game.label.bind("<Button-1>", game.stop_game)
    root.mainloop()

