require "Complex"
Output.Clear()

a = Complex.New(10.2,0.0)
b = Complex.New(0.0,20.3)
c = Complex.Add(a, b)
d = Complex.Mul(c, Complex.i)

Output.WriteLn("c = "..tostring(c.r).." + "..tostring(c.i).."i")
Output.WriteLn("d = "..tostring(d.r).." + "..tostring(d.i).."i")
 