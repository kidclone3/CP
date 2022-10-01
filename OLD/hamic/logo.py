import turtle as tu


class logo:
    def __init__(self):
        
        self.pen = tu.Turtle()
        self.pen.hideturtle()
        self.pen.speed(0)
        self.x_offset = 300
        self.y_offset = 300


    def go(self, x, y):
        self.pen.penup()
        self.pen.goto(x-self.x_offset,(y*-1)+self.y_offset)
        self.pen.pendown()  


    def paint(self,coord,co=(0,0,0)):
        self.pen.color(co)
        t_x,t_y = coord[0]
        self.go(t_x,t_y)
        self.pen.fillcolor(co)
        self.pen.begin_fill()
        t = 0
        for i in coord[1:]:
            print(i)
            x,y = i
            if t:
                self.go(x,y)
                t = 0
                self.pen.begin_fill()
                continue
            if x == -1 and y == -1:
                t = 1
                self.pen.end_fill()
                continue
            else:
                self.pen.goto(x-self.x_offset,(y*-1)+self.y_offset) 
        self.pen.end_fill()


    def draw_fn(self,coord,mode = 1,co = (0,0,0),thickness = 1):
        co = (co[0]/255,co[1]/255,co[2]/255)

        self.pen.color(co)

        if mode:
            self.pen.width(thickness)
            t_x,t_y = coord[0]
            self.go(t_x,t_y)
            t = 0
            for i in coord[1:]:
                print(i)
                x,y = i
                if t:
                    self.go(x,y)
                    t = 0
                    continue
                if x == -1 and y == -1:
                    t = 1
                    continue
                else:
                    self.pen.goto(x-self.x_offset,(y*-1)+self.y_offset)
        else:
            self.paint(coord=coord,co = co)

    
    def draw(self,retain=True):
        self.draw_fn(self.dress,mode = 0)
        self.draw_fn(self.face,mode = 0)
        self.draw_fn(self.iface,co = (255,255,255),mode = 0)
        self.draw_fn(self.mouth,mode = 0)
        self.draw_fn(self.nose,mode = 0)
        self.draw_fn(self.ebrow,mode = 0)
        self.draw_fn(self.lines,mode = 1,thickness=2)
        self.draw_fn(self.eyes,mode = 0)
        self.draw_fn(self.eball,mode = 0,co = (255,255,255))
        if retain:
            tu.done()
pen = logo()
pen.draw()