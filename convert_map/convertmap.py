import json

with open('map.json') as f:
    data = json.load(f)

base = 'evil be_evil%d ={\n  .x = %d,\n  .y = %d,\n  .id = %d,\n  .type = %s,\n  .next = &be_evil%d\n};\n'

name = input('Nom de la map: ')

nombre = input('Nombre d\'objets: ')
nombre = int(nombre)

ping = ''

h = open('map.h', 'a')

for i in range(nombre):
    print(str(i))
    type = data['layers'][2]['objects'][i]['class']
    match type:
        case '0':
            ping = 'false'
        case '1':
            ping = 'true'
        case '2':
            continue
    h.write(base % (i, data['layers'][2]['objects'][i]['x'], data['layers'][2]['objects'][i]['y'], data['layers'][2]['objects'][i]['id'], ping, i-1))