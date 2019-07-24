#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex02/main_basic';
						my $output;
						my $expected;
						die "ex02/main_basic failed to run: $?" if $?;

						


						$output = `$program`;
					
						my $count_lines = 0;
						my $errors = 0;
						foreach my $line (grep / -> [01]\Z/, split /\n/, $output) {
							$count_lines++;
							if ($line !~ / -> 1\Z/) {
								say "!!!! ERROR in work/ex02/main_basic (line $count_lines): '$line'";
								$errors++;
							}
							# debug
							# else { say "passing: '$line'"; }
						}
						if ($count_lines < 6) {
							say "!!!! ERROR in work/ex02/main_basic: expected 6 lines, got $count_lines";
						} elsif ($errors == 0) {
							say 'work/ex02/main_basic good!';
						}
					
						
						


					