import pygame
from pygame.locals import *

class Hopper:
    # initialize all variables
    
    def __init__(self, newX, newY):
        self.x = newX
        self.y = newY
        self.up = False
        self.upCounter = 0
        self.img = pygame.image.load("dude.gif")
        self.steps = 10    
    # draw hopper
    def draw(self, window):
        window.blit(self.img, (self.x,self.y))
        self.windowx = window.get_width()
        self.windowy = window.get_height()
        
        
    # move left unless you hit the edge
    def moveLeft(self):
        self.x -= self.steps
        if self.x < 0:
            self.x = 0
        
    # move left unless you hit the edge 
    def moveRight(self):
        self.x += self.steps
        if self.x > self.windowx - self.getRec()[2]:
            self.x = self.windowx - self.getRec()[2]
    
    # This DOES NOT change self.y
    # sets self.up to True if the self.up variable is False and self.upCounter is 0
    def moveUp(self):
        if (not self.up) and (self.upCounter == 0):
            self.up = True
        
    
    # moves hopper up or down based on the values
    # of self.up and self.upCounter
    def update(self):
        if self.up:
            self.y -= self.steps
            self.upCounter += 1
            if self.upCounter == 10:
                self.up = False

        elif self.upCounter > 0:
            for i in range(self.upCounter):
                self.y += self.steps
            self.upCounter = 0
    
    
    # determine if hopper has collided with an object 
    def collide(self, other):
        # Get other's x, y, width and height
        
        otherrec = other.getRec()
        
        # Get person's width and height
        selfrec = self.getRec()
        
        
        if otherrec[0] + otherrec[2] < selfrec[0]:
            return False
        if selfrec[0] + selfrec[2] < otherrec[0]:
            return False
        if otherrec[1] + otherrec[3] < selfrec[1]:
            return False
        if selfrec[1] + selfrec[3] < otherrec[1]:
            return False
        return True

    
    # DO NOT CHANGE THIS
    # This method returns a rectangle - (x, y, width, height) - that represents
    # the object
    def getRec(self):
        myRec = self.img.get_rect()
        return (self.x, self.y, myRec[2], myRec[3])