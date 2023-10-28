import pygame
from pygame.locals import *
from Wall_231027_proj_Kun import *

class Person:
    # set all class variables in the constructor
    def __init__(self, newX, newY):
        self.x = newX
        self.y = newY
        self.steps = 10
        self.img = pygame.image.load("dude_231027_proj_Kun.gif")
    
    # draw your image
    def draw(self, window:pygame.Surface):
        window.blit(self.img, (self.x, self.y))
        self.windowx = window.get_width()
        self.windowy = window.get_height()
        
    # move left unless you hit the edge
    def moveLeft(self):
        self.x -= self.steps
        if self.x < 0:
            self.x = 0
    
    # move right unless you hit the edge
    def moveRight(self):
        self.x += self.steps
        if self.x > self.windowx - self.getRec()[2]:
            self.x = self.windowx - self.getRec()[2]
        
    # move up unless you hit the edge
    def moveUp(self):
        self.y -= self.steps
        if self.y < 0:
            self.y = 0
        
    # move down unless you hit the edge
    def moveDown(self):
        self.y += self.steps
        if self.y > self.windowy - self.getRec()[3]:
            self.y = self.windowy - self.getRec()[3]
    
    
    # This will be filled out in 2.ifs_collide_lab. 
    # It will return True if your person has 
    # collided with another object
    def collide(self, other:Wall):
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