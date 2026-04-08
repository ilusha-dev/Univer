import pygame

pygame.init()

screen = pygame.display.set_mode((600, 400))

color = (255, 255, 255)
running = True
text = ""
font = pygame.font.Font(None, 100)

while running: 


    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False 
    
        if event.type == pygame.KEYDOWN.KEYDOWN:
            if event.key == pygame.K_a:
                color = (255, 0, 0)
                text = "A"
            if event.key == pygame.K_s:
                color = (0, 255, 0)
                text = "S"
            if event.key == pygame.K_d:
                color = (0, 0, 255)
                text = "D"
        screen.fill(color)
        if text:
            label = font.render(text,
                                True (255, 255, 255))
            rect = label.get_rect(center = (300, 200))
            screen.blit(label, rect)

        pygame.display.flip()

pygame.quit()