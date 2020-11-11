// Arup Guha
// 6/26/2012
// Solution to Southeast Regional Problem G: A No-Win Situation

import java.util.*;

class hand {

	public int value;
	public int numAces;

	public hand() {
		value = 0;
		numAces = 0;
	}

	// Makes a copy of a hand.
	public hand(hand other) {
		value = other.value;
		numAces = other.numAces;
	}

	// Adds c to the hand.
	public void addCard(char c) {

		if ('2' <= c && c <= '9')
			value += (c - '0');
		else if (c != 'A')
			value += 10;
		else {
			value += 11;
			numAces++;
		}
	}

	// Calculates our best possible value. Returns lowest busted value, if busted.
	public int realValue() {

		if (value <= 21)
			return value;

		int aces = numAces, saveVal = value;
		while (aces > 0 && saveVal > 21) {
			aces--;
			saveVal -= 10;
		}
		return saveVal;
	}

	// Returns if this hand is a bust.
	public boolean bust() {
		return realValue() > 21;
	}
}

public class nowin {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		String deck = stdin.next();

		// Go through each case.
		while (!deck.equals("JOKER")) {

			if (canWin(deck))
				System.out.println("Yes");
			else
				System.out.println("No");
			deck = stdin.next();
		}
	}

	public static boolean canWin(String deck) {

		char[] c = deck.toCharArray();

		// Set up initial hand.
		hand me = new hand();
		me.addCard(c[0]);
		me.addCard(c[2]);
		hand dealer = new hand();
		dealer.addCard(c[1]);
		dealer.addCard(c[3]);

		char[] rest =(deck.substring(4)).toCharArray();

		// i = extra cards tried.
		for (int i=0; i<rest.length; i++) {

			hand mecopy = new hand(me);
			hand dealercopy = new hand(dealer);

			// Add my extra cards.
			int j;
			for (j=0; j<i; j++)
				mecopy.addCard(rest[j]);

			// No point in trying more cases.
			if (mecopy.bust()) break;

			// Add the dealer's cards by the 17 rule.
			while (j<rest.length && dealercopy.realValue() < 17)
				dealercopy.addCard(rest[j++]);

			// I won in this case.
			if (mecopy.realValue() >= dealercopy.realValue() || dealercopy.bust())
				return true;
		}

		// No way for me to win.
		return false;
	}
}