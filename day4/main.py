from card import Card


def parse_input(filename):
    with open(filename) as ifile:
        return [Card(line) for line in ifile.readlines()]

def win_cards(cards):
    card_counts = {card.id: 1 for card in cards}
    card_map = {card.id: card for card in cards}

    for card_id in range(1, len(cards)+1):
        wins = card_map[card_id].win_ids()
        for win in wins:
            if win <= len(cards):
                card_counts[win] += card_counts[card_id]
    return card_counts.values()

def main():
    cards = parse_input("input")
    print(sum(card.score() for card in cards))
    print(sum(win_cards(cards)))


if __name__ == '__main__':
    main()
