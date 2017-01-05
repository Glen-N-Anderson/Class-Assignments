import turtle
window = turtle.Screen()
Glen = turtle.Turtle()
def star(x,y):	 
	Glen.clear()
	Glen.reset()
	for i in range(0,5):
		Glen.right(144)
		Glen.forward(100)
		x = x + 1
window.onclick(star)
window.mainloop()
