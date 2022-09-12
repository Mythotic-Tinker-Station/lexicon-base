pipeline{

    agent any

    options {
        disableConcurrentBuilds()
    }

    environment {
        discordWebHookUrl = credentials('efbc440a-0d19-4ca1-b9fa-5db6a8112071')
    }
    
    stages{
        stage("Build") {
            steps {
                echo "=========Building PK3 File has started========="
                discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Creation Magic has been invoked!', 
                    description: 'Build' + env.BUILD_ID  + ":" + env.BRANCH_Name, 
                    footer: 'Lexicon Automata Cube',
                    customUsername: '.',
                    customAvatarUrl: 'https://cdn.discordapp.com/attachments/677086996182859786/884703330734063656/mifu-cube.png',
                    showChangeset: true,
                    thumbnail: 'https://cdn.discordapp.com/attachments/677086996182859786/884703330734063656/mifu-cube.png'
                )
                sh './automata.sh'
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