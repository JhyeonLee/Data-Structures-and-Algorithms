package utils

import (
	"errors"
	"log"
)

func Even(a int) bool {
	return a%2 == 0
}
func Odd(a int) bool {
	return a%2 != 0
}

func FindIndex(A []int, k int) int {
	for index, value := range A {
		if value == k {
			return index
		}
	}
	return -1
}

var logFn = log.Panic

func HandleErr(err error) {
	if err != nil {
		logFn(err)
	}
}

func InvalidRankException() error {
	return errors.New("invalid Rank Exception")
}

func EmptyListException() error {
	return errors.New("empty List Exception")
}

func EmptyStackException() error {
	return errors.New("empty Stack Exception")
}

func EmptyQueueException() error {
	return errors.New("empty Queue Exception")
}

func EmptyDequeException() error {
	return errors.New("empty Deque Exception")
}

func IsNotElement() error {
	return errors.New("It is not Element in the Array")
}

func InvalidNodeException() error {
	return errors.New("invalid Node Exception")
}

func WrongOrderTypeException() error {
	return errors.New("wrong OrderType Exception")
}

func NoSuchKey() error {
	return errors.New("no Such Key")
}
