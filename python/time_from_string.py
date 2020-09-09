def get_multiplier(_unit):
    multipler = 1
    if not _unit:
        return multipler
    multipler *= 10
    if _unit is 'ms':
        return multipler
    multipler *= 100
    if _unit is 's':
        return multipler
    multipler *= 60
    if _unit is 'm':
        return multipler
    multipler *= 60
    if _unit is 'h':
        return multipler
    return 1

def string_time(_time) -> int:
    value = list()
    unit = list()

    for i in _time:
        value.append(i) if i.isdigit() else unit.append(i)

    return int(str().join(value))*get_multiplier(unit[0])
