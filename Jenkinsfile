pipeline{
    agent any

    options {
        disableConcurrentBuilds()
    }

    env {
        discordWebHookUrl = credentials('discord-web-hook')
    }
    
    stages{
        stage("Build") {
            steps {
                echo "=========Building PK3 File has started========="
                discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Creation Magic has been invoked!', 
                    description: 'Build' + env.BUILD_ID  + ":" + hash, 
                    footer: 'Lexicon Automata Cube',
                    customUsername: '.',
                    customAvatarUrl: '.',
                    thumbnail: 'https://cdn.discordapp.com/attachments/677086996182859786/884703330734063656/mifu-cube.png'
                )
                sh ./automata.sh
            }
        }
    }
    post{
        always{
            echo "========always========"
        }
        success{
            echo "========pipeline executed successfully ========"
        }
        failure{
            echo "========pipeline execution failed========"
        }
    }
}