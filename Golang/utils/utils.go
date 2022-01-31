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
