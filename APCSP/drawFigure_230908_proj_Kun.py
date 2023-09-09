import pygame
import sys

pygame.init()

window = pygame.display.set_mode((220, 150))

window.fill((150, 150, 150))

def drawoval(x, y):
  pygame.draw.circle(window, (135, 206, 235), (x, y), 20)

drawoval(70, 25)
drawoval(150, 25)

pygame.draw.rect(window, (0, 84, 119), (70, 25, 80, 80))

pygame.draw.line(window, (0, 0, 0), (70, 65), (150, 65))

pygame.display.update()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT or ( event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE ):
            pygame.quit()
            sys.exit()
