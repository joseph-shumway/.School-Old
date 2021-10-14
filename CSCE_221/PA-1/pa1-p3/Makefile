#################
# GRADING SETUP #
#################

# GIT UPDATE AGENT
# Env variable settings
export REMOTE=updates
export REMOTE_URL="https://github.tamu.edu/alex-born/csce221-pa1-p3"

update:
	git-update-agent

setup-grading:
	planr build

grade:
	planr eval

clean:
	planr clean

deliverable:
	planr/scripts/deliverable.bash

.PHONY: update setup-grading grade deliverable
