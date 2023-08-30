import pygame, random

def drawScene(window):
    # Loads an image
    img = pygame.image.load("Catwalk.gif")

    img = pygame.transform.scale(img,(100,100))

    img2 = pygame.image.load("cat.gif")

    img3 = pygame.image.load("bird.gif")
    # Draws the image on the screen that is passed to it
    window.blit(img, (30,40))

    window.blit(img2, (100, 200))

    window.blit(img3, (300, 0))

    # This will draw a circle a random spot
    pygame.draw.circle(window, (255,0,0),(random.randint(100,400),random.randint(0,300)), 50)
    pygame.draw.circle(window, (0,255,0),(random.randint(0,300),random.randint(0,300)), 10)
    pygame.draw.circle(window, (0,0,255),(random.randint(300,600),random.randint(300,600)), 30)
    # This will draw a rectangle a random spot
    pygame.draw.rect(window, (0,255,0),(random.randint(100,400),random.randint(0,300), 150, 150))
    pygame.draw.rect(window, (255,0,0),(random.randint(0,600),random.randint(0,300), 30, 70))
    pygame.draw.rect(window, (0,0,255),(random.randint(150,450),random.randint(0,300), 60, 50))
