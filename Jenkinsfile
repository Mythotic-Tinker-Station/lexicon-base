pipeline{

    agent any

    options {
        disableConcurrentBuilds()
    }

    environment {
        discordWebHookUrl = credentials('efbc440a-0d19-4ca1-b9fa-5db6a8112071')
        discordImg = 'https://cdn.discordapp.com/attachments/677086996182859786/884703330734063656/mifu-cube.png'
        FILE_NAME="Lexicon_basepack"
    }
    
    stages{
        stage("Build") {
            steps {
                echo "=========Building PK3 File has started========="
                discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Creation Magic has been invoked!', 
                    description: 'Lexicon Base Map Pack Build ' + env.BUILD_ID  + " on branch " + env.BRANCH_Name, 
                    footer: 'Lexicon Automata Cube',
                    customUsername: "Afina's Lexicon Creation Cube",
                    customAvatarUrl: discordImg,
                    showChangeset: true,
                    thumbnail: discordImg
                )
                sh 'chmod +x ./automata.sh && ./automata.sh'
                echo "=========Building PK3 Complete========="
            }
        }
        stage("Rename PK3 File") {
            steps {
                echo "=========Renaming PK3 File to ${FILE_NAME}_${BRANCH_NAME}_${BUILD_NUMBER}.pk3========="
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