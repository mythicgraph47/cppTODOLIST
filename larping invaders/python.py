import pygame
import random

pygame.init()

screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()

#Background
background = pygame.image.load("background.png")

#Title and Icon
pygame.display.set_caption("Larping Invader")
icon = pygame.image.load("dumbbell.png")
pygame.display.set_icon(icon)

#Player/Player Models
playerIMG = pygame.image.load("spaceship.png")
playerIMG = pygame.transform.scale(playerIMG, (64, 64))
playerX = 368
playerY = 480
playerX_change = 0

#Enemy/Enemy Models
enemyIMG = pygame.image.load("enemy.png")
enemyX = random.randint(0, 300)
enemyY = random.randint(0, 100)
enemyX_change = 3
enemyY_change = 40

#Ready


#Fire


#Bullet/Bullet Models
bulletIMG = pygame.image.load("bullet.png")
bulletIMG = pygame.transform.scale(bulletIMG, (40,40))
bulletX = 0
bulletY = 480
bulletX_change = 0
bulletY_change = 40
bullet_state = "ready"



def player(x, y):
    screen.blit(playerIMG, (x, y))

def enemy(x, y):
    screen.blit(enemyIMG, (x, y))

def fire_bullet(x, y):
    global bullet_state
    bullet_state = "fire"
    screen.blit(bulletIMG, (x + 16, y + 10)) #Adding 16 and 10 for spawn location of bullet from spaceship of its Origin

#Game Loop
running = True
while running:

    #RGB = Red, Green, Blue
    screen.fill((0, 0, 0))

    #Background IMG
    screen.blit(background, (0, 0))
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
        #If keystroke is pressed check weather its Right or Left
        if event.type == pygame.KEYDOWN:
            print("A keystoke is pressed")
            if event.key == pygame.K_LEFT:
                playerX_change = -5
                print("Left Arrow is pressed")
            if event.key == pygame.K_RIGHT:
                playerX_change = 5
                print("Right Arrow is pressed")
            if event.key == pygame.K_SPACE:
                #Getting the current x coordinate of the spaceship
                bulletX = playerX
                fire_bullet(playerX, bulletY)

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                playerX_change = 0
                print("Keystroke has been released")

#Checking for boundaries of Models
    playerX += playerX_change
        
    if playerX <= 0:
        playerX = 0
    elif playerX >= 736:
        playerX = 736

    enemyX += enemyX_change
        
    if enemyX <= 0:
        enemyX_change = 3
        enemyY += enemyY_change
    elif enemyX >= 736:
        enemyX_change = -3
        enemyY += enemyY_change
    
#Bullet Movement

    #Multiple Bullet

    if bulletY <= 0:
     bulletY = 480
     bullet_state = "ready"

    #Bullet (SHOOT ONCE)
    if bullet_state is "fire":
        fire_bullet(bulletX, bulletY)
        bulletY -= bulletY_change


    player(playerX, playerY)
    enemy(enemyX, enemyY)
    pygame.display.update()

    clock.tick(60)