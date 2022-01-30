package utils

import "errors"

func InvalidRankException() error {
	return errors.New("invalid Rank Exception")
}

func EmptyListException() error {
	return errors.New("empty List Exception")
}
