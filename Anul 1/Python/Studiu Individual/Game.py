import turtle
import time 

wn = turtle.Screen()
wn.title("Joc Pong by Python AI")
wn.bgcolor("black")
wn.setup(width=800, height=600)
wn.tracer(0) 

moving_up_a = False
moving_down_a = False
moving_up_b = False
moving_down_b = False
PADDLE_SPEED = 1.5
BALL_START_SPEED = 0.9
BALL_ACCELERATION = 0.15

paddle_a = turtle.Turtle()
paddle_a.speed(0) 
paddle_a.shape("square")
paddle_a.color("white")
paddle_a.shapesize(stretch_wid=5, stretch_len=1) 
paddle_a.penup() 
paddle_a.goto(-350, 0) 

paddle_b = turtle.Turtle()
paddle_b.speed(0)
paddle_b.shape("square")
paddle_b.color("white")
paddle_b.shapesize(stretch_wid=5, stretch_len=1)
paddle_b.penup()
paddle_b.goto(350, 0)

ball = turtle.Turtle()
ball.speed(0)
ball.shape("circle")
ball.color("white")
ball.penup()
ball.goto(0, 0)
ball.dx = BALL_START_SPEED 
ball.dy = BALL_START_SPEED 

score_a = 0
score_b = 0
pen = turtle.Turtle()
pen.speed(0)
pen.color("white")
pen.penup()
pen.hideturtle() 
pen.goto(0, 260)
pen.write("Jucator A: 0  Jucator B: 0", align="center", font=("Courier", 24, "normal"))

def press_w():
    global moving_up_a
    moving_up_a = True
def release_w():
    global moving_up_a
    moving_up_a = False
def press_s():
    global moving_down_a
    moving_down_a = True
def release_s():
    global moving_down_a
    moving_down_a = False
def press_up():
    global moving_up_b
    moving_up_b = True
def release_up():
    global moving_up_b
    moving_up_b = False
def press_down():
    global moving_down_b
    moving_down_b = True
def release_down():
    global moving_down_b
    moving_down_b = False

# Legaturi tastatura
wn.listen() 
wn.onkeypress(press_w, "w")
wn.onkeypress(press_s, "s")
wn.onkeypress(press_up, "Up")
wn.onkeypress(press_down, "Down")
wn.onkeyrelease(release_w, "w")
wn.onkeyrelease(release_s, "s")
wn.onkeyrelease(release_up, "Up")
wn.onkeyrelease(release_down, "Down")

while True:
    wn.update() 
    time.sleep(0.005) 

    if moving_up_a and paddle_a.ycor() < 240:
        paddle_a.sety(paddle_a.ycor() + PADDLE_SPEED)
    if moving_down_a and paddle_a.ycor() > -240:
        paddle_a.sety(paddle_a.ycor() - PADDLE_SPEED)
    if moving_up_b and paddle_b.ycor() < 240:
        paddle_b.sety(paddle_b.ycor() + PADDLE_SPEED)
    if moving_down_b and paddle_b.ycor() > -240:
        paddle_b.sety(paddle_b.ycor() - PADDLE_SPEED)

    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)

    if ball.ycor() > 290 or ball.ycor() < -290:
        ball.dy *= -1 
    if ball.xcor() > 390 or ball.xcor() < -390:
        ball.goto(0, 0)
        import random
        ball.dx = BALL_START_SPEED * random.choice([-1, 1])
        ball.dy = BALL_START_SPEED * random.choice([-1, 1])
        
        if ball.xcor() > 390:
            score_a += 1
        else:
            score_b += 1
        pen.clear() 
        pen.write(f"Jucator A: {score_a}  Jucator B: {score_b}", align="center", font=("Courier", 24, "normal"))

    if (ball.xcor() > 340 and ball.xcor() < 350) and (ball.ycor() < paddle_b.ycor() + 50 and ball.ycor() > paddle_b.ycor() - 50):
        ball.setx(340)
        ball.dx *= -1
        if ball.dx < 0:
            ball.dx -= BALL_ACCELERATION
        else:
            ball.dx += BALL_ACCELERATION


    if (ball.xcor() < -340 and ball.xcor() > -350) and (ball.ycor() < paddle_a.ycor() + 50 and ball.ycor() > paddle_a.ycor() - 50):
        ball.setx(-340)
        ball.dx *= -1
        if ball.dx < 0:
            ball.dx -= BALL_ACCELERATION
        else:
            ball.dx += BALL_ACCELERATION
