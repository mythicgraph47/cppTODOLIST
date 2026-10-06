import pygame

#Initializing
pygame.init()
clock = pygame.time.Clock()

#Display and Background
screen = pygame.display.set_mode((800,600))
background = pygame.image.load("background.png")

#Title and Icon
title = pygame.display.set_caption("Larping Invaders")
icon = pygame.image.load("dumbbell.png")
pygame.display.set_icon(icon)

#Player Models
playerIMG = pygame.image.load("spaceship.png")
playerIMG = pygame.transform.scale(playerIMG, (64, 64))
playerX = 378
playerY = 480

#Enemy Models
enemyIMG = pygame.image.load("enemy.png")
enemyX = 378
enemyY = 680


def player(x, y):
    screen.blit(playerIMG, (x, y))

def enemy(x, y):
    screen.blit(enemyIMG, (x, y))
#Game Loop
running = True
while running:
    screen.fill((0, 0, 0))
    screen.blit(background, (0, 0))
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False



    player(playerX, playerY)
    enemy(enemyX, enemyY)
    pygame.display.update()    

    clock.tick(60)
    