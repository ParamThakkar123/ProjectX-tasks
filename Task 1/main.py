import pygame
from particle import Particle

WIDTH, HEIGHT = 800, 600

screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()

particle = Particle(WIDTH // 2, HEIGHT // 2, 5)

run = True

while run:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
            
    screen.fill((255, 255, 255))
    particle.move()
    particle.draw(screen)
    pygame.display.flip()
    clock.tick(60)
    
pygame.quit()