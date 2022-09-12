pipeline{

    agent any

    options {
        disableConcurrentBuilds()
    }

    environment {
        discordWebHookUrl = credentials('efbc440a-0d19-4ca1-b9fa-5db6a8112071')
        discordImg = 'https://cdn.discordapp.com/attachments/677086996182859786/884703330734063656/mifu-cube.png'
        FILE_NAME="Lexicon_basepack"
        SITE_LOCATION="/var/www/mythotic.com/lexicon/builds/lexicon_base_pack/"
    }
    
    stages{
        stage("Build on Branch") {
            when {
                branch "dev"
            }
            steps {
                echo "=========Building PK3 File has started========="
                discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Creation Magic has been invoked!',
                    link: env.BUILD_URL,
                    description: 'Lexicon Base Map Pack Build ' + env.BUILD_ID  + " on " + env.BRANCH_Name, 
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
        stage("Build on Tag") {
            when {
                tag "v*"
            }
            steps {
                echo "=========Building PK3 File has started========="
                discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Creation Magic has been invoked!',
                    link: env.BUILD_URL,
                    description: 'Lexicon Base Map Pack Build ' + env.BUILD_ID  + " on " + env.TAG_NAME + '\n' + 'Oh shit, a new release?!', 
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
        stage("Rename Branch PK3 File") {
            when {
                branch "dev"
            }
            steps {
                echo "=========Renaming PK3 File to ${FILE_NAME}_${BRANCH_NAME}_${BUILD_NUMBER}.pk3========="
                sh 'mv -v ./${FILE_NAME}.pk3 ./${FILE_NAME}_${BRANCH_NAME}_${BUILD_NUMBER}.pk3'
                withEnv(["FULL_FILENAME=${FILE_NAME}_${BRANCH_NAME}_${BUILD_NUMBER}.pk3"])
                echo "=========Renaming Complete========="
            }
        }
        stage("Rename Release PK3 File") {
            when {
                tag "v*"
            }
            steps {
                echo "=========Renaming PK3 File to ${FILE_NAME}_${TAG_NAME}.pk3========="
                sh 'mv -v ./${FILE_NAME}.pk3 ./${FILE_NAME}_${TAG_NAME}.pk3'
                withEnv(["FULL_FILENAME=${FILE_NAME}_${TAG_NAME}.pk3"])
                echo "=========Renaming Complete========="
            }
        }
        stage("Deploy Dev File to Web Server Dev Folder") {
            when {
                branch "dev"
            }
            steps {
                echo "=========Copying ${FULL_FILENAME} to dev build folder website========="
                sh 'cp -v ./${FULL_FILENAME} ${SITE_LOCATION}/dev'
                echo "=========Copying Complete========="
                echo "=========Saving Artifacts========="
                archiveArtifacts artifacts: env.FULL_FILENAME, followSymlinks: false, onlyIfSuccessful: true
                
            }
        }
        stage("Deploy Release to Web Server Stable Folder") {
            when {
                tag "v*"
            }
            steps {
                echo "=========Copying ${FULL_FILENAME} to stable build folder website========="
                sh 'cp -v ./${FULL_FILENAME} ${SITE_LOCATION}/stable'
                echo "=========Copying Complete========="
                echo "=========Saving Artifacts========="
                archiveArtifacts artifacts: env.FULL_FILENAME, followSymlinks: false, onlyIfSuccessful: true
            }
        }
    }
    post{
        success{
            echo "========Pipeline Successful. Executing Post Mortem Actions========"
            echo "========Sending Success Discord Notif========"
            discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Creation Complete!',
                    link: env.BUILD_URL, 
                    description: 'Lexicon Base Map Pack Build Complete with filename ' + env.FULL_FILENAME, 
                    footer: 'Lexicon Automata Cube',
                    customUsername: "Afina's Lexicon Creation Cube",
                    customAvatarUrl: discordImg,
                    showChangeset: true,
                    thumbnail: discordImg,
                    result: 'SUCCESS'
                )

        }
        failure{
            echo "========Pipeline Failed. Executing Really Really Post Mortem Actions========"
            discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Afina ran out of Mana!',
                    link: env.BUILD_URL, 
                    description: 'Lexicon Base Map Pack Build failed with filename ' + env.FULL_FILENAME + '. Please check the jobs logs to determine failure', 
                    footer: 'Lexicon Automata Cube',
                    customUsername: "Afina's Lexicon Creation Cube",
                    customAvatarUrl: discordImg,
                    showChangeset: true,
                    thumbnail: discordImg,
                    result: 'FAILURE'
                )
        }
    }
}