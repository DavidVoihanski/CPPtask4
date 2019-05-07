/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		// testcase.setname("Play with smart guesser");
		// RandomChooser randy;
		// SmartGuesser smarty;
		// for (uint i=0; i<100; ++i) {
		// 	testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		// }

		//My tests********************************************
		ConstantGuesser g123{"123"};
		ConstantChooser c222{"222"};

		testcase.setname("MyTests- test play")
		.CHECK_EQUAL(play(c1234, g123, 4, 100),101) //Guesser looses by making an illegal guess (too short)
		.CHECK_EQUAL(play(c1234, g1234, 5, 101), 0);//Chooser looses by choosing an illegal number (too short)

		testcase.setname("MyTests- Test calculateBullAndPgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234", "6666"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("123","222"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("333","323"), "2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1533","5336"), "1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1","1"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1","9"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("8409","0498"), "1,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1212","2121"), "0,4")
		.CHECK_OUTPUT(calculateBullAndPgia("1212","1221"), "2,2");

		SmartGuesser dummy;
		AnswerObj ans{4, 0};
		testcase.setname("MyTests- test excetions")
		.CHECK_THROWS(play(c1234, g1234, -1, 5)) //illegal length
		.CHECK_THROWS(play(c1234, g1234, 0, 5))	//illegal lengh
		.CHECK_THROWS(play(c1234, g1234, 4, -1)) //illegal max turns
		.CHECK_THROWS(calculateBullAndPgia("1234", "123")) //Guess is too short
		.CHECK_THROWS(calculateBullAndPgia("123", "1234"))//Guess is too long
		.CHECK_THROWS(calculateBullAndPgia("1a1", "1a1"))//illegal input
		.CHECK_THROWS(calculateBullAndPgia("1a1", "123"))//illegal input
		.CHECK_THROWS(calculateBullAndPgia("123", "1a1"))//illegal input
		.CHECK_THROWS(dummy.learn(ans))//learning before the game starts
		.CHECK_THROWS(dummy.startNewGame(0))//illegal input, gamecan't be 0 length
		.CHECK_THROWS(dummy.startNewGame(-5))//illegal input, negative length
		.CHECK_THROWS(c1234.choose(0))//illegal length
		.CHECK_THROWS(c12345.choose(-1)); //illegal length

		testcase.setname("MyTests- general testing")
		.CHECK_OK(dummy.startNewGame(5))
		.CHECK_OK(dummy.learn(ans))
		.CHECK_OK(std::string s = dummy.guess());
		ans = AnswerObj(6, 1);
		testcase.CHECK_THROWS(dummy.learn(ans)); //too many bulls and pgia for legth 5
		//should always win, up to legth 4, with less than 100 steps
		// for(uint i = 0; i<100; i++){
		// 	testcase.CHECK_EQUAL(play(randy, smarty, 1, 100) <= 100, true);
		// 	testcase.CHECK_EQUAL(play(randy, smarty, 2, 100) <= 100, true);
		// 	testcase.CHECK_EQUAL(play(randy, smarty, 3, 100) <= 100, true);
		// }
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	testcase.print_signal(signal);
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

