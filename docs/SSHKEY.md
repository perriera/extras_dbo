## [Generating a new SSH key and adding it to the ssh-agent](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

### Generating a new SSH key and adding it to the ssh-agent

    ssh-keygen -t ed25519 -C "your_email@example.com"

Make sure the email address you use is the same one on your github account.

Hit enter till you see a prompt...

    cat ~/.ssh/id_ed25519.pub

Copy and paste the contents of that file into your github account under **User->Settings->SSH & GPG** keys

