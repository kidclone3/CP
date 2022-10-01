import pygame
import os
f = open("test.txt", "r")
a = []
window = ""
offset = (300, 300)
def readfile():
	for i in f.readlines():
		pos = i.split()
		x = float(pos[0]) * 10
		y = float(pos[1]) * 10
		a.append((x, y))
def draw(n):
	x = n[0] + offset[0]
	y = n[1] + offset[1]
	pygame.draw.rect(window, pygame.Color(0, 132, 198), [x - 0.5, y - 0.5, 1, 1], 1)
	
if __name__ == '__main__':
	pygame.init()
	window = pygame.display.set_mode((600,600))
	readfile()
	running = True
	window.fill((255, 255, 255))
	i = 0
	while(running):
		if i < len(a) : draw(a[i])
		pygame.display.update()
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
			   running = False
		i += 1
		# if i >= len(a) :running = False