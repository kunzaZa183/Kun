# all imports go at the top
import pygame, sys, random, time

def updatethenwait():
  pygame.display.update()
  time.sleep(1)

# create the screen
pygame.init()
screen = pygame.display.set_mode((800,600))


# make a few colors
white = (255, 255, 255)
black = (0, 0, 0)
blue = (0, 0, 255)
red = (255, 0, 0)
green = (0, 128, 0)
grey = (128, 128, 128)

#use the colors above to change the screen color
screen.fill( blue )

# Updates the display
updatethenwait()

screen.fill(grey)

updatethenwait()

screen.fill(black)

updatethenwait()

screen.fill(white)

updatethenwait()
           
while (True):
  for event in pygame.event.get() :
    if ( event.type == pygame.QUIT or (event.type==pygame.KEYDOWN and event.key==pygame.K_ESCAPE)):
      pygame.quit() 
      sys.exit()
            