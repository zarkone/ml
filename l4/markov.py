# Copyright (c) 2012 the authors listed at the following URL, and/or
# the authors of referenced articles or incorporated external code:
# http://en.literateprograms.org/Markov_algorithm_simulator_(Python)?action=history&offset=20090311085513
# 
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
# 
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
# 
# Retrieved from: http://en.literateprograms.org/Markov_algorithm_simulator_(Python)?oldid=16244

successor = [
            # endpoint for 3
             ("_ZZ", "_", True),
             ("1Z1", "Z11", False),
             ("1Z_", "Z1_", False),

            # x < 4, 0, X
             ("_111*", "_X", False),
             ("_11*", "_X", False),
             ("_1*", "_X", False),
             ("X1", "X", False),
             ("X*", "X", False),
             ("X_", "_", True),
            # x = 4, z, Y 
             ("_1111*", "_Y", False),
             ("Y1", "Y", False),
             ("Y*", "_", True),
             ("Y_", "_", True),
            # x > 4, x+2, =% 
             ("_1", "_=111", False),
             ("1_", "%_", False),
             ("1%", "%", False),
             ("*%", "*", False),
            #  x/y. =0^Z
             ("_=0", "_Z1=", False),
             ("=0", "1=", False),
             ("^0", "01", False),
             ("1*1" , "^*" , False),
             ("1^", "^1", False),
             ("=**", "1Z_" , False  ),
             ("^**" , "**" , False ),
             ("1**"  , "1**" , False),
             ("^*"  , "01*" , False),

             ]
def contains(s, sub):
    return s.find(sub) != -1
def find_rule(a, w):
    for l,r,b in a:
        if contains(w, l):
            return l,r,b
    raise ValueError, "not found"
def apply_rule((l,r,b), s):
    return s.replace(l, r, 1)
def apply_alg(a, w):
    _,_,b = r = find_rule(a, w)
    return apply_rule(r, w), b
def run(a, w):
    result = []
    flag = False                      # whether Halting rule was applied
    try:
        while not flag:               # Normal rule was applied
            result.append(w)
            w, flag = apply_alg(a, w) # apply a rule
            print w
        result.append(w)
    except ValueError:                # No rule was applied
        pass
    return result
if __name__ == "__main__":
    run(successor, "_1111*111111111111111111111111*11_")

