# all imports go at the top
import pygame, sys, random, time

# create the screen
pygame.init()
screen = pygame.display.set_mode((800, 600))

# Colors the screen randomly
r = random.randint(0, 255)
g = random.randint(0, 255)
b = random.randint(0, 255)
randColor = (r, g, b)

# use a random color
screen.fill(randColor)

time.sleep(1)

r = random.randint(0, 128)
g = random.randint(0, 255)
b = random.randint(0, 128)
moregreen = (r, g, b)

screen.fill(moregreen)

pygame.display.update()
time.sleep(1)

r = random.randint(0, 255)
g = random.randint(0, 128)
b = random.randint(0, 128)
morered = (r, g, b)

screen.fill(morered)

pygame.display.update()
time.sleep(1)

r = random.randint(0, 128)
g = random.randint(0, 128)
b = random.randint(0, 255)
moreblue = (r, g, b)

screen.fill(moreblue)

pygame.display.update()
time.sleep(1)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT or ( event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE ):
            pygame.quit()
            sys.exit()
