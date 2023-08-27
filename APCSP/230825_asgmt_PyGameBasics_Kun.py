#all imports go at the top
import pygame, sys, time

def updatethenwait():
  pygame.display.update()
  time.sleep(1)

# create the screen
pygame.init()
screen = pygame.display.set_mode((800,600))

# Colors the screen white
white = (255, 255, 255 )
red = (255, 0, 0 )
green = (0, 255, 0)
blue = (0, 0, 255)

screen.fill( white )

# Updates the display
updatethenwait()

screen.fill( red )

updatethenwait()

screen.fill(green)

updatethenwait()

screen.fill(blue)

updatethenwait()

while( True ):
    for event in pygame.event.get() :
         if ( event.type == pygame.QUIT or (event.type==pygame.KEYDOWN and event.key==pygame.K_ESCAPE)):
              pygame.quit()
              sys.exit()