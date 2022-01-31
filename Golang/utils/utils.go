package utils

import (
	"errors"
	"log"
)

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
