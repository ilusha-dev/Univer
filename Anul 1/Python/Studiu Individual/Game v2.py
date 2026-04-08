import tkinter as tk
import random
import sys

from PIL import Image, ImageTk 

WIDTH = 600
HEIGHT = 400
PLAYER_SPEED = 7
ENEMY_SPEED = 1
BULLET_SPEED = 7
ENEMY_SPAWN_RATE = 40 
GAME_TICK = 20
MAX_MISSED_ENEMIES = 5
HIGHEST_SCORE_SESSION = 0

class SpaceInvadersGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Space Invaders Tkinter")
        self.canvas = tk.Canvas(root, bg="black", width=WIDTH, height=HEIGHT)
        self.canvas.pack()

        self.score = 0
        self.missed_count = 0 
        self.running = True
        self.player_ship_id = None 
        self.enemies = []
        self.bullets = []
        self.background_image = None
        self.keys_pressed = {'left': False, 'right': False}
        self.game_over_objects = [] 

        self.score_label = self.canvas.create_text(10, 10, anchor="nw", text=f"Score: {self.score}", font=("Arial", 14), fill="white")
        self.missed_label = self.canvas.create_text(WIDTH - 10, 10, anchor="ne", text=f"Missed: {self.missed_count}/{MAX_MISSED_ENEMIES}", font=("Arial", 14), fill="yellow")
        
        self.create_player()
        self.bind_controls()
        self.game_loop()

    # def load_background(self):
    #     try:
    #         img = Image.open("space_background.png")
    #         img = img.resize((WIDTH, HEIGHT), Image.Resampling.LANCZOS)
    #         self.background_image = ImageTk.PhotoImage(img)
    #         self.canvas.create_image(0, 0, image=self.background_image, anchor="nw")
    #         self.canvas.lift(self.score_label) 
    #         self.canvas.lift(self.missed_label)
    #     except FileNotFoundError:
    #         pass 
    #     except Exception as e:
    #         print(f"Error loading image: {e}")

    def create_player(self):
        center_x = WIDTH/2
        bottom_y = HEIGHT-5
        
        self.player_ship_id = self.canvas.create_polygon(
            center_x, bottom_y - 35,       
            center_x-10, bottom_y - 10,    
            center_x+10, bottom_y - 10,    
            fill="cyan", tags="player_group"
        )
        self.canvas.create_rectangle(center_x-20, bottom_y - 10, center_x+20, bottom_y, fill="blue", tags="player_group")
        self.canvas.create_oval(center_x-5, bottom_y, center_x+5, bottom_y+5, fill="orange", tags="player_group")
        

    def bind_controls(self):
        self.root.bind("<KeyPress-Left>", lambda event: self.handle_key_press(event, 'left'))
        self.root.bind("<KeyRelease-Left>", lambda event: self.handle_key_release(event, 'left'))
        self.root.bind("<KeyPress-Right>", lambda event: self.handle_key_press(event, 'right'))
        self.root.bind("<KeyRelease-Right>", lambda event: self.handle_key_release(event, 'right'))
        self.root.bind("<space>", self.shoot)
    
    def handle_key_press(self, event, key):
        self.keys_pressed[key] = True

    def handle_key_release(self, event, key):
        self.keys_pressed[key] = False

    def move_player(self):
        if self.running:
            coords = self.canvas.coords("player_group")
            if not coords: return 
            x_min = min(coords[::2])
            x_max = max(coords[::2])

            if self.keys_pressed['left'] and x_min > 5:
                self.canvas.move("player_group", -PLAYER_SPEED, 0)
            if self.keys_pressed['right'] and x_max < WIDTH - 5:
                self.canvas.move("player_group", PLAYER_SPEED, 0)

    def shoot(self, event):
        if self.running:
            coords_main_body = self.canvas.coords(self.player_ship_id)
            if not coords_main_body: return

            x_tip = coords_main_body[0]
            y_tip = coords_main_body[1]
            
            bullet = self.canvas.create_rectangle(x_tip-1, y_tip-10, x_tip+1, y_tip, fill="red", tags="bullet")
            self.bullets.append(bullet)

    def spawn_enemy(self):
        if random.randint(1, ENEMY_SPAWN_RATE) == 1:
            x = random.randint(20, WIDTH - 20)
            y = 10
            enemy = self.canvas.create_oval(x-10, y-10, x+10, y+10, fill="gray", outline="white", tags="enemy")
            self.enemies.append(enemy)

    def update_objects(self):
        for bullet in self.bullets[:]:
            self.canvas.move(bullet, 0, -BULLET_SPEED)
            coords = self.canvas.coords(bullet)
            if not coords: continue

            if coords[1] < 0:
                self.canvas.delete(bullet)
                self.bullets.remove(bullet)

        for enemy in self.enemies[:]:
            self.canvas.move(enemy, 0, ENEMY_SPEED)
            coords = self.canvas.coords(enemy)
            if not coords: continue

            if coords[3] > HEIGHT:
                self.canvas.delete(enemy)
                self.enemies.remove(enemy)
                self.missed_count += 1
                self.canvas.itemconfig(self.missed_label, text=f"Missed: {self.missed_count}/{MAX_MISSED_ENEMIES}")

                if self.missed_count >= MAX_MISSED_ENEMIES:
                    self.game_over()
                    return 

    def check_collisions(self):
        for bullet in self.bullets[:]:
            overlap_objects = self.canvas.find_overlapping(*self.canvas.coords(bullet))
            for obj_id in overlap_objects:
                if 'enemy' in self.canvas.gettags(obj_id):
                    self.canvas.delete(bullet)
                    if bullet in self.bullets: self.bullets.remove(bullet)
                    
                    self.canvas.delete(obj_id)
                    if obj_id in self.enemies: self.enemies.remove(obj_id)
                    
                    self.score += 10
                    self.canvas.itemconfig(self.score_label, text=f"Score: {self.score}")
                    break

    def game_over(self):
        global HIGHEST_SCORE_SESSION
        self.running = False
        self.canvas.delete("player_group") 

        if self.score > HIGHEST_SCORE_SESSION:
            HIGHEST_SCORE_SESSION = self.score

        game_over_text_canvas = self.canvas.create_text(WIDTH / 2, HEIGHT / 2 - 50, text="GAME OVER", font=("Arial", 50), fill="red")
        score_text_canvas = self.canvas.create_text(WIDTH / 2, HEIGHT / 2 + 20, text=f"Current Score: {self.score}\nHighest Score: {HIGHEST_SCORE_SESSION}", font=("Arial", 16), fill="white", justify='center')
        
        restart_button = tk.Button(self.root, text="Restart Game", command=self.restart_game, font=("Arial", 14), bg="green", fg="white")
        button_window = self.canvas.create_window(WIDTH / 2, HEIGHT / 2 + 100, window=restart_button)

        self.game_over_objects.extend([game_over_text_canvas, score_text_canvas, button_window])


    def restart_game(self):
        for obj in self.game_over_objects:
            self.canvas.delete(obj)
        self.game_over_objects = []

        for enemy in self.enemies[:]: self.canvas.delete(enemy)
        for bullet in self.bullets[:]: self.canvas.delete(bullet)
        self.enemies = []
        self.bullets = []

        self.score = 0
        self.missed_count = 0
        self.running = True
        self.canvas.itemconfig(self.score_label, text=f"Score: {self.score}")
        self.canvas.itemconfig(self.missed_label, text=f"Missed: {self.missed_count}/{MAX_MISSED_ENEMIES}")

        self.create_player()
        self.game_loop()

    def game_loop(self):
        if self.running:
            self.move_player()
            self.spawn_enemy()
            self.update_objects()
            self.check_collisions()
            self.root.after(GAME_TICK, self.game_loop)
        else:
            pass



if __name__ == "__main__":
    root = tk.Tk()
    game = SpaceInvadersGame(root)
    root.mainloop()
