package utils

import (
	"errors"
	"log"
)

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
