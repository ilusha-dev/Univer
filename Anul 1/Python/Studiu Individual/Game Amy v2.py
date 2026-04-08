import tkinter as tk
import random
import math

# --- Setări Globale Joc ---
WIDTH = 400
HEIGHT = 400
GRID_SIZE = 20
GRID_WIDTH = WIDTH // GRID_SIZE
GRID_HEIGHT = HEIGHT // GRID_SIZE
GAME_SPEED = 120 

class SnakeGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Jocul Șarpelui Avansat")
        self.root.resizable(False, False)

        self.canvas = tk.Canvas(root, bg="#1a1a1a", width=WIDTH, height=HEIGHT, highlightthickness=0)
        self.canvas.pack()

        self.root.bind("<Left>", self.change_direction)
        self.root.bind("<Right>", self.change_direction)
        self.root.bind("<Up>", self.change_direction)
        self.root.bind("<Down>", self.change_direction)

        self.game_state = "running"
        self.score = 0
        self.snake = []
        self.direction = 'Right'
        self.food = None
        
        self.start_game()

    def start_game(self):
        self.canvas.delete(tk.ALL) # Curăță tot la restart
        self.game_state = "running"
        self.score = 0
        start_x = GRID_WIDTH // 2
        start_y = GRID_HEIGHT // 2
        self.snake = [(start_x, start_y), (start_x - 1, start_y), (start_x - 2, start_y)]
        self.direction = 'Right'
        
        self.place_food()
        self.update_score()
        self.move_snake()

    def update_score(self):
        self.root.title(f"Jocul Șarpelui Avansat | Scor: {self.score}")

    def place_food(self):
        while True:
            x = random.randint(0, GRID_WIDTH - 1)
            y = random.randint(0, GRID_HEIGHT - 1)
            self.food = (x, y)
            if self.food not in self.snake:
                break
        
        # Mărul ca un cerc frumos (oval)
        f_x, f_y = self.food
        self.canvas.create_oval(
            f_x * GRID_SIZE + 3, f_y * GRID_SIZE + 3,
            (f_x + 1) * GRID_SIZE - 3, (f_y + 1) * GRID_SIZE - 3,
            fill="red", outline="white", tags="food"
        )

    def move_snake(self):
        if self.game_state != "running":
            return

        head_x, head_y = self.snake[0]

        if self.direction == 'Up':
            new_head = (head_x, head_y - 1)
        elif self.direction == 'Down':
            new_head = (head_x, head_y + 1)
        elif self.direction == 'Left':
            new_head = (head_x - 1, head_y)
        elif self.direction == 'Right':
            new_head = (head_x + 1, head_y)

        self.snake.insert(0, new_head)

        if new_head == self.food:
            self.score += 10
            self.update_score()
            self.canvas.delete("food")
            self.place_food()
        else:
            self.snake.pop()

        self.canvas.delete("snake")
        self.draw_snake()

        if self.check_collisions():
            self.game_over()
        else:
            self.root.after(GAME_SPEED, self.move_snake)

    def draw_snake(self):
        # Desenăm șarpele ca o serie de ovale suprapuse perfect pentru un aspect neted
        for i, (x, y) in enumerate(self.snake):
            # Coordonatele pixelilor pentru centrul celulei
            center_x = x * GRID_SIZE + GRID_SIZE // 2
            center_y = y * GRID_SIZE + GRID_SIZE // 2
            
            radius = GRID_SIZE // 2 # Raza maximă care să umple celula

            # Culoare corp și outline (același, pentru continuitate)
            fill_color = "#00cc00" if i == 0 else "#009900" # Capul e mai deschis

            self.canvas.create_oval(
                center_x - radius, center_y - radius,
                center_x + radius, center_y + radius,
                fill=fill_color, outline=fill_color, tags="snake"
            )
            
            # Adăugăm ochi la capul șarpelui (doar pentru primul segment)
            if i == 0:
                eye_color = "white"
                pupil_color = "black"
                eye_radius = 3
                pupil_radius = 1

                # Determinăm poziția ochilor în funcție de direcție (pentru realism)
                if self.direction in ('Up', 'Down'):
                    # Ochi stânga-dreapta
                    left_eye_x = center_x - GRID_SIZE // 4
                    right_eye_x = center_x + GRID_SIZE // 4
                    eye_y = center_y
                    # Poziție pupilă: sus sau jos
                    pupil_y = eye_y + (eye_radius * (1 if self.direction == 'Down' else -1))
                    
                    self.canvas.create_oval(left_eye_x - eye_radius, eye_y - eye_radius, left_eye_x + eye_radius, eye_y + eye_radius, fill=eye_color, tags="snake")
                    self.canvas.create_oval(left_eye_x - pupil_radius, pupil_y - pupil_radius, left_eye_x + pupil_radius, pupil_y + pupil_radius, fill=pupil_color, tags="snake")

                    self.canvas.create_oval(right_eye_x - eye_radius, eye_y - eye_radius, right_eye_x + eye_radius, eye_y + eye_radius, fill=eye_color, tags="snake")
                    self.canvas.create_oval(right_eye_x - pupil_radius, pupil_y - pupil_radius, right_eye_x + pupil_radius, pupil_y + pupil_radius, fill=pupil_color, tags="snake")

                elif self.direction in ('Left', 'Right'):
                    # Ochi sus-jos
                    eye_x = center_x
                    top_eye_y = center_y - GRID_SIZE // 4
                    bottom_eye_y = center_y + GRID_SIZE // 4
                    # Poziție pupilă: stânga sau dreapta
                    pupil_x = eye_x + (eye_radius * (1 if self.direction == 'Right' else -1))

                    self.canvas.create_oval(eye_x - eye_radius, top_eye_y - eye_radius, eye_x + eye_radius, top_eye_y + eye_radius, fill=eye_color, tags="snake")
                    self.canvas.create_oval(pupil_x - pupil_radius, top_eye_y - pupil_radius, pupil_x + pupil_radius, top_eye_y + pupil_radius, fill=pupil_color, tags="snake")

                    self.canvas.create_oval(eye_x - eye_radius, bottom_eye_y - eye_radius, eye_x + eye_radius, bottom_eye_y + eye_radius, fill=eye_color, tags="snake")
                    self.canvas.create_oval(pupil_x - pupil_radius, bottom_eye_y - pupil_radius, pupil_x + pupil_radius, bottom_eye_y + pupil_radius, fill=pupil_color, tags="snake")


    def change_direction(self, event):
        key = event.keysym
        if key == 'Up' and self.direction != 'Down':
            self.direction = 'Up'
        elif key == 'Down' and self.direction != 'Up':
            self.direction = 'Down'
        elif key == 'Left' and self.direction != 'Right':
            self.direction = 'Left'
        elif key == 'Right' and self.direction != 'Left':
            self.direction = 'Right'

    def check_collisions(self):
        head_x, head_y = self.snake[0]
        
        if head_x < 0 or head_x >= GRID_WIDTH or head_y < 0 or head_y >= GRID_HEIGHT:
            return True
        
        if (head_x, head_y) in self.snake[1:]:
            return True
            
        return False

    def game_over(self):
        self.game_state = "gameover"
        self.show_game_over_popup()

    def show_game_over_popup(self):
        popup = tk.Toplevel(self.root)
        popup.title("Game Over!")
        popup.geometry("300x200") 
        popup.grab_set()

        label = tk.Label(popup, text=f"Joc Terminat!\nScorul tău final: {self.score}", font=("Helvetica", 16, "bold"), pady=20)
        label.pack()

        button_frame = tk.Frame(popup)
        button_frame.pack(pady=10)

        restart_button = tk.Button(button_frame, text="Restart Joc", command=lambda: self.restart_game_wrapper(popup), width=15, height=2)
        restart_button.pack(side=tk.LEFT, padx=10)
        
        exit_button = tk.Button(button_frame, text="Ieșire", command=self.root.destroy, width=15, height=2)
        exit_button.pack(side=tk.RIGHT, padx=10)

    def restart_game_wrapper(self, popup_window):
        popup_window.destroy()
        self.start_game()


# --- Rularea aplicației ---
if __name__ == "__main__":
    root = tk.Tk()
    game = SnakeGame(root)
    root.mainloop()
