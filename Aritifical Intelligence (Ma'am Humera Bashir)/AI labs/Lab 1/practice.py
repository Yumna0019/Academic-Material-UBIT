###           tuples
>>> pair=(3,5)
>>> pair[0]
3

>>> x,y =pair
>>> x
3
>>> y
5
>>> x.5
SyntaxError: invalid syntax
>>>pair[1]
5
>>> pair[1]= 6
TypeError: 'tuple' object does not support item assignment

###         set
>>> shapes = ["circle","square","triangle","circle"]
>>> setOfShapes = set(shapes)
>>> set(shapes)
{'triangle', 'circle', 'square'}

>>> setOfShapes.add("polygon")
>>> set(shapes)
{'triangle', 'circle', 'square'}

>>>set
<class 'set'>

>>> setOfShapes
{'triangle', 'circle', 'polygon', 'square'}

>>> "circle" in setOfShapes
True

>>> "apple" in setOfShapes
False

>>> favShapes =  set(["circle","hexagon","triangle"])
>>> favShapes
{'hexagon', 'triangle', 'circle'}

>>> setOfShapes & favShapes
{'triangle', 'circle'}

>>> setOfShapes | favShapes
{'hexagon', 'square', 'triangle', 'circle', 'polygon'}

>>> setOfShapes - favShapes
{'square', 'polygon'}


###     dictionary
>>> studentIds = {'knuth': 42.0, 'turing': 56.0, 'nash': 92.0 }
>>> studentIds["turing"]
56.0

>>> studentIds["nash"]
92.0

>>> studentIds["nash"] = "ninety-two"
>>> studentIds
{'knuth': 42.0, 'turing': 56.0, 'nash': 'ninety-two'}

>>> studentIds["knuth"]=[42.0,"forty-two"]
>>> studentIds
{'knuth': [42.0, 'forty-two'], 'turing': 56.0, 'nash': 'ninety-two'}

>>> studentIds.keys()
dict_keys(['knuth', 'turing', 'nash'])

>>> studentIds.values()
dict_values([[42.0, 'forty-two'], 56.0, 'ninety-two'])

>>> studentIds.items()
dict_items([('knuth', [42.0, 'forty-two']), ('turing', 56.0), ('nash', 'ninety-two')])

>>> len(studentIds)
3
# comment
#######  yumnssdfghjk

>>> s="abc"
>>> dir(s)
['__add__', '__class__', '__contains__', '__delattr__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__getitem__', '__getnewargs__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__iter__', '__le__', '__len__', '__lt__', '__mod__', '__mul__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__rmod__', '__rmul__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', 'capitalize', 'casefold', 'center', 'count', 'encode', 'endswith', 'expandtabs', 'find', 'format', 'format_map', 'index', 'isalnum', 'isalpha', 'isascii', 'isdecimal', 'isdigit', 'isidentifier', 'islower', 'isnumeric', 'isprintable', 'isspace', 'istitle', 'isupper', 'join', 'ljust', 'lower', 'lstrip', 'maketrans', 'partition', 'removeprefix', 'removesuffix', 'replace', 'rfind', 'rindex', 'rjust', 'rpartition', 'rsplit', 'rstrip', 'split', 'splitlines', 'startswith', 'strip', 'swapcase', 'title', 'translate', 'upper', 'zfill']
