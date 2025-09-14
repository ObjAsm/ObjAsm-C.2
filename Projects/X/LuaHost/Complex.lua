Complex = {}

function Complex.New (r, i) 
  return {r=r, i=i}
end

-- defines a constant `i'
Complex.i = Complex.New(0, 1)

function Complex.Add (c1, c2)
  return Complex.New(c1.r + c2.r, c1.i + c2.i)
end

function Complex.Sub (c1, c2)
  return Complex.New(c1.r - c2.r, c1.i - c2.i)
end

function Complex.Mul (c1, c2)
  return Complex.New(c1.r*c2.r - c1.i*c2.i,
                     c1.r*c2.i + c1.i*c2.r)
end

function Complex.Inv (c)
  local n = c.r^2 + c.i^2
  return Complex.New(c.r/n, -c.i/n)
end

return Complex