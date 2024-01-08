import random
import pygame

WIDTH, HEIGHT = 800, 600

class Particle:
    def __init__(self, x, y, size):
        self.x = x
        self.y = y
        self.size = size
        self.dx = random.uniform(-5, 5)
        self.dy = random.uniform(-5, 5)
        
    def move(self):
        self.x += self.dx
        self.y += self.dy
        
        if self.x <= 0 or self.x >= WIDTH:
            self.dx = -self.dx
        if self.y <= 0 or self.y >= HEIGHT:
            self.dy = -self.dy
            
    def draw(self, screen):
        pygame.draw.circle(screen, (0, 0, 255), (self.x, self.y), 12)