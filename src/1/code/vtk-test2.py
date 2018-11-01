
# coding: utf-8
#from tvtk.tools import tvtk_doc
#tvtk_doc.main()
from tvtk.api import tvtk
s=tvtk.CubeSource(x_length=1.0,y_length=2.0,z_length=3.0)
s1=tvtk.ConeSource(radius=1.0,height=2.0)

m=tvtk.PolyDataMapper(input_connection=s1.output_port)

a=tvtk.Actor(mapper=m)

w=tvtk.RenderWindow(size=(300,350))

r=tvtk.Renderer(background=(0,0,0))

r.add_actor(a)

w.add_renderer(r)

i=tvtk.RenderWindowInteractor(render_window=w)
i.initialize()
i.start()

