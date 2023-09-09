import pygame, sys

pygame.init()

window = pygame.display.set_mode((800, 400))

window.fill((255, 255, 255))

blue = (135, 206, 235)

def twoface(x, y):
  pygame.draw.circle(window, (0, 0, 0), (x, y), 100, 3)
  pygame.draw.circle(window, blue, (x - 40, y - 30), 20)
  pygame.draw.circle(window, blue, (x + 40, y - 30), 20)
  pygame.draw.line(window, blue, (x - 45, y + 30), (x + 45, y + 30), 5)
twoface(150, 150)
twoface(450, 250)

pygame.display.update()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT or ( event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE ):
            pygame.quit()
            sys.exit()