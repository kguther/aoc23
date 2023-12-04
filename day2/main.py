from game import Game


def parse_input(filename):
    games = []
    with open(filename) as ifile:
        for line in ifile:
            games.append(Game(line))
    return games


def get_possible_games(games):
    print(sum([game.id for game in games if game.possible()]))


def get_power(games):
    total_power = 0
    for game in games:
        print(game.get_power())
        total_power += game.get_power()
    print(total_power)


def main():
    games = parse_input("input")
    get_possible_games(games)
    get_power(games)



if __name__ == '__main__':
    main()

