import pygame

pygame.init()
font=pygame.font.Font('msyh_boot.ttf',50)
rtext = font.render("thekdl",True,(0,0,0),(255,255,255))
winSur = pygame.display.set_mode((200,200))
rtextRect=rtext.get_rect()

a=pygame.transform.scale(rtext,(30,40))
b=pygame.surfarray.array2d(a)

while True:
    winSur.blit(rtext,rtextRect)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()
    pygame.display.update()                
