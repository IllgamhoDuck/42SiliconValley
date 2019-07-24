#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex01/main_negative';
						my $output;
						my $expected;
						die "ex01/main_negative failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = '-987654321';

						


						if ($output eq $expected) {
							say 'work/ex01/main_negative good!';
						} else {
							say "!!!! ERROR in work/ex01/main_negative: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					